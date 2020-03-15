#pragma once
#include "Repository.h"
class Service {
private:
	Repo repository;
public:
	Service();
	Service(Repo repo);
	~Service();
	void addCheltuialaService(int suma, char* tip);
	void insereazaCheltuialaService(int ziua, int suma, char* tip);
	void deleteCheltuialaService(int ziua);
	void deleteCheltuialaService(int start, int end);
	void deleteCheltuialaService(char* tip);
	Cheltuiala* getCheltuieliService(int& lungime);
	Cheltuiala* getCheltuieliService(char* tip, int& lungime);
	Cheltuiala* getCheltuieliService(char* tip, int comparator, int suma, int& lungime);
	int sumaCheltuieliService(char* tip);
	int maximZiCheltuieliService();
	Cheltuiala* ordonareCheltuieliService(int& lungime);
	Cheltuiala* ordonareCheltuieliService(char* tip, int& lungime);
	void filtrareCheltuieliService(char* tip);
	void filtrareCheltuieliService(char* tip, int comparator, int suma);
	int undoService();
};