#include "FileRepository.h"

FileRepository::FileRepository(const char* airplaneTripsFileName, const char* busTripsFileName, const char* writeFileName, bool textOrCSV)
{
	strcpy_s(this->airplaneTripsFileName, strlen(airplaneTripsFileName), airplaneTripsFileName);
	strcpy_s(this->busTripsFileName, strlen(busTripsFileName), busTripsFileName);
	strcpy_s(this->writeFileName, strlen(writeFileName), writeFileName);
	this->textOrCSV = textOrCSV;
}

FileRepository::FileRepository()
{
	strcpy_s(this->airplaneTripsFileName, 1," ");
	strcpy_s(this->busTripsFileName, 1, " ");
	strcpy_s(this->writeFileName, 1, " ");
	this->textOrCSV = 0;
}

FileRepository::~FileRepository()
{
	if (airplaneTripsFileName)
		delete[] airplaneTripsFileName;
	if (busTripsFileName)
		delete[] busTripsFileName;
	if (writeFileName)
		delete[] writeFileName;
}

void FileRepository::loadBusTripsFromFile()
{	
	this->calatoriiAutobuz = {};
	CalatorieAutobuz calatorie;
	int cod;
	char* localitate_plecare;
	char* localitate_destinatie;
	char* data_plecarii;
	int nr_loc_totale;
	int nr_loc_rezervate;
	int nr_zile;
	std::ifstream fin(busTripsFileName);
	while (!fin.eof()) {
		fin >> cod >> localitate_plecare >> localitate_destinatie >> data_plecarii >> nr_zile >> nr_loc_totale >> nr_loc_rezervate;
		calatorie = CalatorieAutobuz{ cod, localitate_plecare, localitate_destinatie, data_plecarii, nr_zile, nr_loc_totale, nr_loc_rezervate };
		calatoriiAutobuz.push_back(calatorie);
	}
	fin.close();
}

void FileRepository::loadAirplaneTripsFromFile()
{
	this->calatoriiAvion = {};
	CalatorieAvion calatorie;
	int cod;
	char* localitate_plecare;
	char* localitate_destinatie;
	char* data_plecarii;
	int nr_loc_totale;
	int nr_loc_rezervate;
	bool escala;
	std::ifstream fin(airplaneTripsFileName);
	while (!fin.eof()) {
		fin >> cod >> localitate_plecare >> localitate_destinatie >> data_plecarii >> escala >> nr_loc_totale >> nr_loc_rezervate;
		calatorie = CalatorieAvion{ cod, localitate_plecare, localitate_destinatie, data_plecarii, escala, nr_loc_totale, nr_loc_rezervate };
		calatoriiAvion.push_back(calatorie);
	}
	fin.close();
}

void FileRepository::writeTripsToCSVFile()
{
	std::ofstream fout(writeFileName);
	fout << "Cod,Plecare,Destinatie,Data,Durata(zile),Escala,Nr. Locuri totale,Nr. Locuri Rezervate\n";
	for (int i = 0; i < calatoriiAutobuz.size(); ++i) {
		fout << '"' << calatoriiAutobuz[i].getCod() << "\","
			<< '"' << calatoriiAutobuz[i].getLocalitatePlecare() << "\","
			<< '"' << calatoriiAutobuz[i].getLocalitateDestinatie() << "\","
			<< '"' << calatoriiAutobuz[i].getNrZileDurata() << "\","
			<< '"' << " " << "\","
			<< '"' << calatoriiAutobuz[i].getNrLocTotale() << "\","
			<< '"' << calatoriiAutobuz[i].getNrLocRezervate() << '"' << '\n';
	}
	for (int i = 0; i < calatoriiAvion.size(); ++i) {
		fout << '"' << calatoriiAvion[i].getCod() << "\","
			<< '"' << calatoriiAvion[i].getLocalitatePlecare() << "\","
			<< '"' << calatoriiAvion[i].getLocalitateDestinatie() << "\","
			<< '"' << " " << "\",";
		if (calatoriiAvion[i].getEscala() == 1)
			fout << '"' << "DA" << "\",";
		else
			fout << '"' << "NU" << "\",";
			fout << '"' << calatoriiAvion[i].getNrLocTotale() << "\","
			<< '"' << calatoriiAvion[i].getNrLocRezervate() << '"' << '\n';
	}
}

void FileRepository::changeRepoType(bool textOrCSV)
{
	this->textOrCSV = textOrCSV;
}

void FileRepository::writeTripsToTxtFile()
{
	std::ofstream fout(writeFileName);
	for (int i = 0; i < calatoriiAutobuz.size(); ++i)
		fout << "Cod: " << calatoriiAutobuz[i].getCod() << " Plecare: " << calatoriiAutobuz[i].getLocalitatePlecare() << " Destinatie: " << calatoriiAutobuz[i].getLocalitateDestinatie() << " Data: " << calatoriiAutobuz[i].getDataPlecarii() << " Durata(zile): " << calatoriiAutobuz[i].getNrZileDurata() << " Nr.Locuri Totale:" << calatoriiAutobuz[i].getNrLocTotale() << " Nr.Locuri Rezervate: " << calatoriiAutobuz[i].getNrLocRezervate() << '\n';
	for (int i = 0; i < calatoriiAvion.size(); ++i)
	{
		fout << "Cod: " << calatoriiAvion[i].getCod() << " Plecare: " << calatoriiAvion[i].getLocalitatePlecare() << " Destinatie: " << calatoriiAvion[i].getLocalitateDestinatie() << " Data: " << calatoriiAvion[i].getDataPlecarii() << " Escala: ";
		if (calatoriiAvion[i].getEscala() == true)
			fout << "DA";
		else
			fout << "NU";
		fout << " Nr.Locuri Totale:" << calatoriiAvion[i].getNrLocTotale() << " Nr.Locuri Rezervate: " << calatoriiAvion[i].getNrLocRezervate() << '\n';
	}
}

std::vector<CalatorieAutobuz> FileRepository::getAllBusTrips()
{
	return calatoriiAutobuz;
}

std::vector<CalatorieAvion> FileRepository::getAllAirplaneTrips()
{
	return calatoriiAvion;
}

void FileRepository::rezervaLocuri(int cod, int nr_locuri)
{
	CalatorieAutobuz calatorie = CalatorieAutobuz{ cod, "Test", "Test", "15.05.2015", 13, 20, 15 };
	bool gasit = 0;
	for(int i = 0; i < calatoriiAutobuz.size() && !gasit; ++i)
		if (calatoriiAutobuz[i].getCod() == cod)
		{
			gasit = 1;
			if (nr_locuri > calatoriiAutobuz[i].getNrLocTotale - calatoriiAutobuz[i].getNrLocRezervate[i])
				throw RepoException("Numar de locuri indisponibil") ;
		}
	for (int i = 0; i < calatoriiAvion.size() && !gasit; ++i)
		if (calatoriiAvion[i].getCod() == cod)
		{
			gasit = 1;
			if (nr_locuri > calatoriiAvion[i].getNrLocTotale - calatoriiAvion[i].getNrLocRezervate[i])
				throw RepoException("Numar de locuri indisponibil");
		}
	if (!gasit)
		throw RepoException("Cod invalid");
}
