#pragma once
#include <string.h>
class Calatorie
{
protected:
	int cod;
	char localitate_plecare[100];
	char localitate_destinatie[100];
	char data_plecarii[100];
	int nr_loc_totale;
	int nr_loc_rezervate;
public:
	Calatorie();
	Calatorie(int cod,
		const char* localitate_plecare,
		const char* localitate_destinatie,
		const char* data_plecarii,
		int nr_loc_totale,
		int nr_loc_rezervate);
	Calatorie(const Calatorie& b);
	~Calatorie();

	int getCod();
	char* getLocalitatePlecare();
	char* getLocalitateDestinatie();
	char* getDataPlecarii();
	int getNrLocTotale();
	int getNrLocRezervate();


	void setLocalitatePlecare(const char*);
	void setLocalitateDestinatie(const char*);
	void setDataPlecarii(const char*);
	void setNrLocTotale(int);
	void setNrLocRezervate(int);

	Calatorie& operator=(const Calatorie& b);
	bool operator==(const Calatorie& b);

};

