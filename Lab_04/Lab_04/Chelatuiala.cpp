#include "Chelatuiala.h"
#include <cstring>
Cheltuiala::Cheltuiala()
{
	this->ziua = 0;
	this->suma = 0;
	this->tip = NULL;
}

Cheltuiala::Cheltuiala(int ziua, int suma, char* tip)
{
	this->ziua = ziua;
	this->suma = suma;
	strcpy(this->tip, tip);
}

Cheltuiala::Cheltuiala(const Cheltuiala& c)
{
	this->ziua = c.ziua;
	this->suma = c.suma;
	this->tip =  new char[strlen(c.tip) + 1];
	strcpy(this->tip, c.tip);
}

Cheltuiala::~Cheltuiala()
{
	if (this->tip) {
		delete[] this->tip;
		this->tip = NULL;
	}
}

int Cheltuiala::getZiua()
{
	return this->ziua;
}

int Cheltuiala::getSuma()
{
	return this->suma;
}

char* Cheltuiala::getTip()
{
	return this->tip;
}

void Cheltuiala::setZiua(int ziua)
{
	this->ziua = ziua;
}

void Cheltuiala::setSuma(int suma)
{
	this->suma = suma;
}

void Cheltuiala::setTip(char* tip)
{
	strcpy(this->tip, tip);
}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c)
{
	this->setSuma(c.suma);
	this->setZiua(c.ziua);
	this->setTip(c.tip);
	return *this;
}

bool Cheltuiala::operator==(const Cheltuiala& c)
{
	return strcmp(this->tip, c.tip) == 0 && this->ziua == c.ziua && this->suma == c.suma;
}

ostream& operator<<(ostream& os, const Cheltuiala& c)
{
	os << "Zi: " << c.ziua << " Suma: " << c.suma << " Tip: " << c.tip;
	return os;
}
