#pragma once
#include <ostream>
using namespace std;

class Cheltuiala {
private:
	int ziua;
	int suma;
	char* tip;
public:
	Cheltuiala();
	Cheltuiala(int ziua, int suma, char* tip);
	Cheltuiala(const Cheltuiala& c);
	~Cheltuiala();
	int getZiua();
	int getSuma();
	char* getTip();
	void setZiua(int ziua);
	void setSuma(int suma);
	void setTip(char* tip);
	Cheltuiala& operator= (const Cheltuiala& c);
	bool operator== (const Cheltuiala& c);
	friend ostream& operator<<(ostream& os, const Cheltuiala& c);


};