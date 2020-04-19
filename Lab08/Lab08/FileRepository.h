#pragma once
#include "CalatorieAutobuz.h"
#include "CalatorieAvion.h"
#include <vector>
#include <fstream>
#include "RepoException.h"

class FileRepository
{
private:
	std::vector<CalatorieAutobuz> calatoriiAutobuz;
	std::vector<CalatorieAvion> calatoriiAvion;
	bool textOrCSV;
	char* airplaneTripsFileName;
	char* busTripsFileName;
	char* writeFileName;
public:
	FileRepository(const char* tripsFileName, const char* busTripsFileName, const char* writeFileName, bool textOrCSV = 0);
	FileRepository();
	~FileRepository();
	void loadBusTripsFromFile();
	void loadAirplaneTripsFromFile();
	void writeTripsToTxtFile();
	void writeTripsToCSVFile();
	void changeRepoType(bool textOrCSV);
	std::vector<CalatorieAutobuz> getAllBusTrips();
	std::vector<CalatorieAvion> getAllAirplaneTrips();
	void rezervaLocuri(int cod, int nr_locuri);

};

