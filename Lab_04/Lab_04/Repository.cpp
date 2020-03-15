#include "Repository.h"

Repo::Repo()
{
	this->length = 0;
	this->indexIstoric = -1;
}

Repo::~Repo()
{
	this->length = 0;
	this->indexIstoric = -1;
	delete[] this->cheltuieli;
	for (int i = 0; i < indexIstoric; ++i)
		delete[] this->istoric[indexIstoric];
}

void Repo::addCheltuiala(Cheltuiala c)
{
	this->cheltuieli[this->length++] = c;
	appendInIstoric();
}

void Repo::appendInIstoric()
{
	char p[20] = "NULL";
	this->indexIstoric++;
	for (int i = 0; i < this->length; ++i)
		this->istoric[this->indexIstoric][i] = this->cheltuieli[i];
	this->istoric[this->indexIstoric][this->length].setTip(p);
}

void Repo::deleteCheltuiala(int ziua)
{
	int i, j;
	for (i = 0; i < this->length; ++i)
		if (this->cheltuieli[i].getZiua() == ziua) {
			for (j = i; j < this->length; ++j)
				this->cheltuieli[j] = this->cheltuieli[j + 1];
			i--;
			this->length--;
		}
	appendInIstoric();
}

void Repo::deleteCheltuiala(int start, int end)
{
	int i, j;
	for (i = 0; i < this->length; ++i)
		if (this->cheltuieli[i].getZiua() >= start && this->cheltuieli[i].getZiua() <= end) {
			for (j = i; j < this->length; ++j)
				this->cheltuieli[j] = this->cheltuieli[j + 1];
			i--;
			this->length--;
		}
	appendInIstoric();
}

void Repo::deleteCheltuiala(char* tip)
{
	int i, j;
	for (i = 0; i < this->length; ++i)
		if (strcmp(this->cheltuieli[i].getTip(), tip) == 0) {
			for (j = i; j < this->length; ++j)
				this->cheltuieli[j] = this->cheltuieli[j + 1];
			i--;
			this->length--;
		}
	appendInIstoric();
}

Cheltuiala* Repo::getCheltuieli(int& lungime)
{
	lungime = this->length;
	return this->cheltuieli;
}

Cheltuiala* Repo::getCheltuieli(char* tip, int& lungime)
{
	lungime = 0;
	Cheltuiala listaCheltuieli[100];
	int i;
	for(i = 0; i < this->length; ++i)
		if (strcmp(this->cheltuieli[i].getTip(), tip) == 0) {
			listaCheltuieli[lungime++] = this->cheltuieli[i];
		}
	return listaCheltuieli;
}

/*
	comparator = -1 <=> "<"
	comparator = 0 <=> "="
	comparator = 1 <=> ">"
*/

Cheltuiala* Repo::getCheltuieli(char* tip, int comparator, int suma, int& lungime)
{
	lungime = 0;
	Cheltuiala listaCheltuieli[100];
	int i;
	if (comparator == -1) {
		for (i = 0; i < this->length; ++i)
			if (strcmp(this->cheltuieli[i].getTip(), tip) == 0 && this->cheltuieli[i].getSuma() < suma) {
				listaCheltuieli[lungime++] = this->cheltuieli[i];
			}
	}
	else
		if(comparator == 0)
		{
			for (i = 0; i < this->length; ++i)
				if (strcmp(this->cheltuieli[i].getTip(), tip) == 0 && this->cheltuieli[i].getSuma() == suma) {
					listaCheltuieli[lungime++] = this->cheltuieli[i];
				}
		}
		else
		{
			for (i = 0; i < this->length; ++i)
				if (strcmp(this->cheltuieli[i].getTip(), tip) == 0 && this->cheltuieli[i].getSuma() > suma) {
					listaCheltuieli[lungime++] = this->cheltuieli[i];
				}
		}
	return listaCheltuieli;
}

int Repo::sumaCheltuieli(char* tip)
{
	int suma = 0;
	int i;
	for (i = 0; i < this->length; ++i)
		if (strcmp(this->cheltuieli[i].getTip(), tip) == 0) {
			suma += this->cheltuieli[i].getSuma();
		}
	return suma;
}

int Repo::maximZiCheltuieli()
{
	int i, sumaMax = -1, ziuaMax = -1, suma;
	for (int ziua = 1; ziua <= 31; ++ziua) {
		suma = 0;
		for (i = 0; i < this->length; ++i)
			if (this->cheltuieli[i].getZiua() == ziua) {
				suma += this->cheltuieli[i].getSuma();
			}
		if (suma > sumaMax) {
			sumaMax = suma;
			ziuaMax = ziua;
		}
	}
	return ziuaMax;
}

Cheltuiala* Repo::ordonareCheltuieli(int& lungime)
{
	lungime = 0;
	bool sortat = 1;
	Cheltuiala listaCheltuieli[100], aux;
	int i;
	for (i = 0; i < this->length; ++i)
			listaCheltuieli[lungime++] = this->cheltuieli[i];
	while (!sortat) {
		sortat = 1;
		for(i = 0; i < lungime - 1; ++i)
			if (listaCheltuieli[i].getSuma() < listaCheltuieli[i + 1].getSuma()) {
				aux = listaCheltuieli[i];
				listaCheltuieli[i] = listaCheltuieli[i + 1];
				listaCheltuieli[i + 1] = aux;
			}
	}
	return listaCheltuieli;
}

Cheltuiala* Repo::ordonareCheltuieli(char* tip, int& lungime)
{
	lungime = 0;
	bool sortat = 1;
	Cheltuiala listaCheltuieli[100], aux;
	int i;
	for (i = 0; i < this->length; ++i)
		if (strcmp(this->cheltuieli[i].getTip(), tip) == 0) {
			listaCheltuieli[lungime++] = this->cheltuieli[i];
		}
	while (!sortat) {
		sortat = 1;
		for (i = 0; i < lungime - 1; ++i)
			if (listaCheltuieli[i].getSuma() > listaCheltuieli[i + 1].getSuma()) {
				aux = listaCheltuieli[i];
				listaCheltuieli[i] = listaCheltuieli[i + 1];
				listaCheltuieli[i + 1] = aux;
			}
	}
	return listaCheltuieli;
}

void Repo::filtrareCheltuieli(char* tip)
{
	int i, j;
	for (i = 0; i < this->length; ++i)
		if (strcmp(this->cheltuieli[i].getTip(), tip) != 0) {
			for (j = i; j < this->length; ++j)
				this->cheltuieli[j] = this->cheltuieli[j + 1];
			i--;
			this->length--;
		}
	appendInIstoric();
}

void Repo::filtrareCheltuieli(char* tip, int comparator, int suma)
{
	int i, j;
	if (comparator == -1) {
		for (i = 0; i < this->length; ++i)
			if (strcmp(this->cheltuieli[i].getTip(), tip) != 0 && this->cheltuieli[i].getSuma() >= suma) {
				for (j = i; j < this->length; ++j)
					this->cheltuieli[j] = this->cheltuieli[j + 1];
				i--;
				this->length--;
			}
	}
	else
		if (comparator == 0)
		{
			for (i = 0; i < this->length; ++i)
				if (strcmp(this->cheltuieli[i].getTip(), tip) != 0 && this->cheltuieli[i].getSuma() != suma) {
					for (j = i; j < this->length; ++j)
						this->cheltuieli[j] = this->cheltuieli[j + 1];
					i--;
					this->length--;
				}
		}
		else
		{
			for (i = 0; i < this->length; ++i)
				if (strcmp(this->cheltuieli[i].getTip(), tip) != 0 && this->cheltuieli[i].getSuma() <= suma) {
					for (j = i; j < this->length; ++j)
						this->cheltuieli[j] = this->cheltuieli[j + 1];
					i--;
					this->length--;
				}
		}
	appendInIstoric();
}

int Repo::undo()
{
	if(this->indexIstoric == -1)
		return -1;
	for (int i = 0; strcmp(this->istoric[indexIstoric][i].getTip(), "NULL") == 0; ++i)
		this->cheltuieli[i] = this->istoric[indexIstoric][i];
	indexIstoric--;
	return 1;
}


