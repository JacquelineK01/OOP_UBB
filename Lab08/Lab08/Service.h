#pragma once
#include "FileRepository.h"
class Service
{
private:
	FileRepository repo;
public:
	Service(FileRepository repo) {};
	Service() {};
	~Service() {};
	void changeTxtOrCSV(bool textOrCSV);
	void rezervare(int cod, int nr_locuri);
	std::vector<CalatorieAutobuz> calatoriiAutobuzInData(const char* data);
	std::vector<CalatorieAvion> calatoriiAvionInData(const char* data);
};

