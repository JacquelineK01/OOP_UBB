#include "Tests.h"

void runTests()
{
	void testDestroyCheltuiala();
	void testGetZiua();
	void testGetSuma();
	void testGetTip();
	void testSetZiua();
	void testSetSuma();
	void testSetTip();
}

void testCheltuiala()
{
	char value3[30];
	strcpy(value3, "Mancare");
	Cheltuiala c = Cheltuiala(1, 2, value3);
	assert(c.getZiua() == 1);
	assert(c.getSuma() == 2);
	assert(strcmp(c.getTip(), value3) == 0);
}

void testDestroyCheltuiala()
{
	//~Cheltuiala();
}

void testGetZiua()
{
	char value3[30];
	strcpy(value3, "Mancare");
	Cheltuiala c = Cheltuiala(1, 2, value3);
	assert(c.getZiua() == 1);
}

void testGetSuma()
{
	char value3[30];
	strcpy(value3, "Mancare");
	Cheltuiala c = Cheltuiala(1, 2, value3);
	assert(c.getSuma() == 2);
}

void testGetTip()
{
	char value3[30];
	strcpy(value3, "Mancare");
	Cheltuiala c = Cheltuiala(1, 2, value3);
	assert(strcmp(c.getTip(), value3) == 0);
}

void testSetZiua(int ziua)
{
	char value3[30];
	strcpy(value3, "Mancare");
	Cheltuiala c = Cheltuiala(1, 2, value3);
	c.setZiua(2);
	assert(c.getZiua() == 2);
}

void testSetSuma(int suma)
{
	char value3[30];
	strcpy(value3, "Mancare");
	Cheltuiala c = Cheltuiala(1, 2, value3);
	c.setSuma(3);
	assert(c.getSuma() == 3);
}

void testSetTip(char* tip)
{
	char value3[30];
	strcpy(value3, "Mancare");
	Cheltuiala c = Cheltuiala(1, 2, value3);
	char value4[30];
	strcpy(value4, "Apa");
	c.setTip(value4);
	assert(strcmp(c.getTip(), value4) == 0);
}
