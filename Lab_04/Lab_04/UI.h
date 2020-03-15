#pragma once
#include "Service.h"
#include <stdio.h>
#include <iostream>
#include <ostream>

using namespace std;
class UI {
private:
	Service service;
public:
	UI(Service serv);
	~UI();
	void start();
	void addCheltuiala();
	void insereazaCheltuiala();
	void deleteCheltuiala();
	void getCheltuieli();
	void sumaCheltuieli();
	void maximZiCheltuieli();
	void ordonareCheltuieli();
	void filtrareCheltuieli();
	void undo();
};