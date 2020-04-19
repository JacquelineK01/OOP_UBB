#include "Calatorie.h"
#include <cstring>

Calatorie::Calatorie()
{
	this->cod = 0;
	this->localitate_plecare = NULL;
	this->localitate_destinatie = NULL;
	this->data_plecarii = NULL;
	this->nr_loc_totale = 0;
	this->nr_loc_rezervate = 0;
}

Calatorie::Calatorie(int cod,
	const char* localitate_plecare,
	const char* localitate_destinatie,
	const char* data_plecarii,
	int nr_loc_totale,
	int nr_loc_rezervate){
	this->cod = cod;

	this->localitate_plecare = new char[strlen(localitate_plecare) + 1];
	strcpy_s(this->localitate_plecare, strlen(localitate_plecare) + 1, localitate_plecare);

	this->localitate_destinatie = new char[strlen(localitate_destinatie) + 1];
	strcpy_s(this->localitate_destinatie, strlen(localitate_destinatie) + 1, localitate_destinatie);

	this->data_plecarii = new char[strlen(data_plecarii) + 1];
	strcpy_s(this->data_plecarii, strlen(data_plecarii) + 1, data_plecarii);

	this->nr_loc_totale = nr_loc_totale;

	this->nr_loc_rezervate = nr_loc_rezervate;
}

Calatorie::Calatorie(const Calatorie& a)
{
	this->cod = a.cod;

	this->localitate_plecare = new char[strlen(a.localitate_plecare) + 1];
	strcpy_s(this->localitate_plecare, strlen(a.localitate_plecare) + 1, a.localitate_plecare);

	this->localitate_destinatie = new char[strlen(a.localitate_destinatie) + 1];
	strcpy_s(this->localitate_destinatie, strlen(a.localitate_destinatie) + 1, a.localitate_destinatie);

	this->data_plecarii = new char[strlen(a.data_plecarii) + 1];
	strcpy_s(this->data_plecarii, strlen(a.data_plecarii) + 1, a.data_plecarii);

	this->nr_loc_totale = a.nr_loc_totale;

	this->nr_loc_rezervate = a.nr_loc_rezervate;
}

Calatorie::~Calatorie()
{
	this->cod = 0;

	if (this->localitate_plecare)
	{
		delete[] this->localitate_plecare;
		this->localitate_plecare == NULL;
	}

	if (this->localitate_destinatie)
	{
		delete[] this->localitate_destinatie;
		this->localitate_destinatie == NULL;
	}

	if (this->data_plecarii)
	{
		delete[] this->data_plecarii;
		this->data_plecarii == NULL;
	}
	this->nr_loc_totale = 0;

	this->nr_loc_rezervate = 0;
}

//----------------------------------------------------GETERI----------------------------------------------------

int Calatorie::getCod()
{
	return this->cod;
}

char* Calatorie::getLocalitatePlecare()
{
	return this->localitate_plecare;
}

char* Calatorie::getLocalitateDestinatie()
{
	return this->localitate_destinatie;
}

char* Calatorie::getDataPlecarii()
{
	return this->data_plecarii;
}

int Calatorie::getNrLocTotale()
{
	return this->nr_loc_totale;
}

int Calatorie::getNrLocRezervate()
{
	return this->nr_loc_rezervate;
}

//----------------------------------------------------SETERI----------------------------------------------------

void Calatorie::setLocalitatePlecare(const char* localitate_plecare)
{
	if (this->localitate_plecare != NULL)
	{
		delete[] this->localitate_plecare;
		this->localitate_plecare = NULL;
	}
	this->localitate_plecare = new char[strlen(localitate_plecare) + 1];
	strcpy_s(this->localitate_plecare, strlen(localitate_plecare) + 1, localitate_plecare);
}

void Calatorie::setLocalitateDestinatie(const char* localitate_destinatie)
{
	if (this->localitate_destinatie != NULL)
	{
		delete[] this->localitate_destinatie;
		this->localitate_destinatie = NULL;
	}
	this->localitate_destinatie = new char[strlen(localitate_destinatie) + 1];
	strcpy_s(this->localitate_destinatie, strlen(localitate_destinatie) + 1, localitate_destinatie);
}

void Calatorie::setDataPlecarii(const char* data_plecarii)
{
	if (this->data_plecarii != NULL)
	{
		delete[] this->data_plecarii;
		this->data_plecarii = NULL;
	}
	this->data_plecarii = new char[strlen(data_plecarii) + 1];
	strcpy_s(this->data_plecarii, strlen(data_plecarii) + 1, data_plecarii);
}



void Calatorie::setNrLocTotale(int nr_loc_totale)
{
	this->nr_loc_totale = nr_loc_totale;
}

void Calatorie::setNrLocRezervate(int nr_loc_rezervate)
{
	this->nr_loc_rezervate = nr_loc_rezervate;
}

//--------------------------------------------------OPERATORI-------------------------------------------------------------

Calatorie& Calatorie::operator=(const Calatorie& a)
{
	this->cod = a.cod;

	if (this->localitate_plecare)
	{
		delete[] this->localitate_plecare;
		this->localitate_plecare == NULL;
	}
	this->localitate_plecare = new char[strlen(a.localitate_plecare) + 1];
	strcpy_s(this->localitate_plecare, strlen(a.localitate_plecare) + 1, a.localitate_plecare);

	if (this->localitate_destinatie)
	{
		delete[] this->localitate_destinatie;
		this->localitate_destinatie == NULL;
	}
	this->localitate_destinatie = new char[strlen(a.localitate_destinatie) + 1];
	strcpy_s(this->localitate_destinatie, strlen(a.localitate_destinatie) + 1, a.localitate_destinatie);

	if (this->data_plecarii)
	{
		delete[] this->data_plecarii;
		this->data_plecarii == NULL;
	}
	this->data_plecarii = new char[strlen(a.data_plecarii) + 1];
	strcpy_s(this->data_plecarii, strlen(a.data_plecarii) + 1, a.data_plecarii);

	this->nr_loc_totale = a.nr_loc_totale;
	this->nr_loc_rezervate = a.nr_loc_rezervate;
	return *this;
}

bool Calatorie::operator==(const Calatorie& b)
{
	return b.cod == cod;
}

