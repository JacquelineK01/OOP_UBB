#include "Service.h"
#include <iostream>
void Service::changeTxtOrCSV(bool textOrCSV)
{
	this->textOrCSV = textOrCSV;
	repo.changeRepoType(textOrCSV);
}

void Service::rezervare(int cod, int nr_locuri)
{
	repo.rezervaLocuri(cod, nr_locuri);
}

std::vector<CalatorieAutobuz> Service::calatoriiAutobuzInData(const char* data)
{
	std::vector<CalatorieAutobuz> calatorii = repo.getAllBusTrips(), calatoriiFinale = {};
	for (int i = 0; i < calatorii.size(); ++i)
		if (strcmp(calatorii[i].getDataPlecarii(), data) == 0)
			calatoriiFinale.push_back(calatorii[i]);

	return calatoriiFinale;
}

std::vector<CalatorieAvion> Service::calatoriiAvionInData(const char* data)
{
	std::vector<CalatorieAvion> calatorii = repo.getAllAirplaneTrips(), calatoriiFinale = {};
	for (int i = 0; i < calatorii.size(); ++i)
		if (strcmp(calatorii[i].getDataPlecarii(), data) == 0)
			calatoriiFinale.push_back(calatorii[i]);
	return calatoriiFinale;
}

void Service::scrieCalatoriiInFisier(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion)
{
	std::cout << "BOOL: " << textOrCSV << "\n";
	if (textOrCSV == 0)
		repo.writeTripsToTxtFile(calatoriiAutobuz, calatoriiAvion);
	else
		repo.writeTripsToCSVFile(calatoriiAutobuz, calatoriiAvion);
}
