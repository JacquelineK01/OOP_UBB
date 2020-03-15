#pragma once
#include "Chelatuiala.h"

class Repo {
private:
	Cheltuiala cheltuieli[100];
	int length;
	Cheltuiala istoric[200][20];
	int indexIstoric;
public:
	Repo();
	~Repo();
	void addCheltuiala(Cheltuiala c);
	void appendInIstoric();
	void deleteCheltuiala(int ziua);
	void deleteCheltuiala(int start, int end);
	void deleteCheltuiala(char* tip);
	Cheltuiala* getCheltuieli(int &lungime);
	Cheltuiala* getCheltuieli(char* tip, int& lungime);
	Cheltuiala* getCheltuieli(char* tip, int comparator, int suma, int& lungime);
	int sumaCheltuieli(char* tip);
	int maximZiCheltuieli();
	Cheltuiala* ordonareCheltuieli(int& lungime);
	Cheltuiala* ordonareCheltuieli(char* tip, int& lungime);
	void filtrareCheltuieli(char* tip);
	void filtrareCheltuieli(char* tip, int comparator, int suma);
	int undo();
};