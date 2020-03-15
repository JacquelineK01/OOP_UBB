#include "Service.h"
#include <iostream>
Service::Service()
{
}

Service::Service(Repo repo)
{
	cout << 4;
	this->repository = repo;
}

Service::~Service()
{
	//Repo(this->repository);
}

void Service::addCheltuialaService(int suma, char* tip)
{
	int ziuaCurenta = 31;
	Cheltuiala c = Cheltuiala(ziuaCurenta, suma, tip);
	this->repository.addCheltuiala(c);
}

void Service::insereazaCheltuialaService(int ziua, int suma, char* tip)
{
	Cheltuiala c = Cheltuiala(ziua, suma, tip);
	this->repository.addCheltuiala(c);
}

void Service::deleteCheltuialaService(int ziua)
{
	this->repository.deleteCheltuiala(ziua);
}

void Service::deleteCheltuialaService(int start, int end)
{
	this->repository.deleteCheltuiala(start, end);
}

void Service::deleteCheltuialaService(char* tip)
{
	this->repository.deleteCheltuiala(tip);
}

Cheltuiala* Service::getCheltuieliService(int& lungime)
{
	return this->repository.getCheltuieli(lungime);
}

Cheltuiala* Service::getCheltuieliService(char* tip, int& lungime)
{
	return this->repository.getCheltuieli(tip, lungime);
}

Cheltuiala* Service::getCheltuieliService(char* tip, int comparator, int suma, int& lungime)
{
	return this->repository.getCheltuieli(tip, comparator, suma, lungime);
}

int Service::sumaCheltuieliService(char* tip)
{
	return this->repository.sumaCheltuieli(tip);
}

int Service::maximZiCheltuieliService()
{
	return this->repository.maximZiCheltuieli();
}

Cheltuiala* Service::ordonareCheltuieliService(int& lungime)
{
	return this->repository.ordonareCheltuieli(lungime);
}

Cheltuiala* Service::ordonareCheltuieliService(char* tip, int& lungime)
{
	return this->repository.ordonareCheltuieli(tip, lungime);
}

void Service::filtrareCheltuieliService(char* tip)
{
	this->repository.filtrareCheltuieli(tip);
}

void Service::filtrareCheltuieliService(char* tip, int comparator, int suma)
{
	this->repository.filtrareCheltuieli(tip, comparator, suma);
}

int Service::undoService()
{
	return this->repository.undo();
}
