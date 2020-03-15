#include "UI.h"

UI::UI(Service serv)
{
	this->service = serv;
}

UI::~UI()
{
	//~Service(service);
}

void UI::start()
{
	char consoleInput[50];
	while (1) {
		cout << "Input: ";
		scanf("%s", consoleInput);
		if (strcmp(consoleInput, "exit") == 0) {
			//~UI();
			break;
		}
		else if (strcmp(consoleInput, "adauga") == 0) {
			addCheltuiala();
		}
		else if (strcmp(consoleInput, "insereaza") == 0) {
			insereazaCheltuiala();
		}
		else if (strcmp(consoleInput, "elimina") == 0) {
			deleteCheltuiala();
		}
		else if (strcmp(consoleInput, "listeaza") == 0) {
			getCheltuieli();
		}
		else if (strcmp(consoleInput, "suma") == 0) {
			sumaCheltuieli();
		}
		else if (strcmp(consoleInput, "max") == 0) {
			maximZiCheltuieli();
		}
		else if (strcmp(consoleInput, "soartare") == 0) {
			ordonareCheltuieli();
		}
		else if (strcmp(consoleInput, "filtrare") == 0) {
			filtrareCheltuieli();
		}
		else if (strcmp(consoleInput, "undo") == 0) {
			undo();
		}
	}
}

void UI::addCheltuiala()
{
	int value1;
	scanf("%d", value1);
	char value2[20];
	scanf("%s", value2);
	this->service.addCheltuialaService(value1, value2);
}

void UI::insereazaCheltuiala()
{
	int value1, value2;
	char value3[20];
	scanf("%d", value1);
	scanf("%d", value2);
	scanf("%s", value3);
	this->service.insereazaCheltuialaService(value1, value2, value3);
}

void UI::deleteCheltuiala()
{
	char value1[20];
	scanf("%s", value1);
	if (value1[0] >= '9' || value1[0] <= '0')
		this->service.deleteCheltuialaService(value1);
	else
	{
		int number = 0;
		for (int i = 0; i < strlen(value1); ++i)
			number = number * 10 + value1[i] - '0';
		char value2[20] = "";
		gets_s(value2);
		if (strlen(value2) == 0)
			service.deleteCheltuialaService(number);
		else
		{
			int value3;
			scanf("%d", value3);
			service.deleteCheltuialaService(number, value3);
		}

	}

}

void UI::getCheltuieli()
{
	char value1[20] = "";
	Cheltuiala *cheltuieli;
	int lungime = 0;
	gets_s(value1);
	if (strlen(value1) == 0) {
		cheltuieli = service.getCheltuieliService(lungime);
	}
	else
	{
		char value2[30];
		scanf("%s", value2);
		char value3[30] = "";
		gets_s(value3);
		if (strlen(value3) == 0)
			cheltuieli = service.getCheltuieliService(value3, lungime);
		else
		{
			int value4;
			scanf("%d", value4);
			if(strcmp(value3, "=") == 0)
				cheltuieli = service.getCheltuieliService(value3, 0, value4, lungime);
			else
				if (strcmp(value3, ">") == 0)
					cheltuieli = service.getCheltuieliService(value3, 1, value4, lungime);
				else
					cheltuieli = service.getCheltuieliService(value3, -1, value4, lungime);
		}
	}
	for (int i = 0; i < lungime; ++i)
		cout << cheltuieli[i] << '\n';
}

void UI::sumaCheltuieli()
{
	char value1[30];
	scanf("%s", value1);
	cout << service.sumaCheltuieliService(value1);

}

void UI::maximZiCheltuieli()
{
	char value1[30];
	scanf("%s", value1);
	cout << service.maximZiCheltuieliService();

}

void UI::ordonareCheltuieli()
{
	char value1[30];
	Cheltuiala* cheltuieli;
	int lungime = 0;
	scanf("%s", value1);
	if(strcmp(value1, "zi") == 0)
	{
		cheltuieli = service.ordonareCheltuieliService(lungime);
	}
	else {
		cheltuieli = service.ordonareCheltuieliService(value1,lungime);
	}
	for (int i = 0; i < lungime; ++i)
		cout << cheltuieli[i] << '\n';
}

void UI::filtrareCheltuieli()
{
	char value1[20] = "";
	scanf("%s", value1);
	char value2[30] = "";
	gets_s(value2);
	if (strlen(value2) == 0)
		service.filtrareCheltuieliService(value1);
	else {
		int value3;
		scanf("%d", value3);
		if (strcmp(value2, "=") == 0)
			service.filtrareCheltuieliService(value1, 0, value3);
		else
			if (strcmp(value2, ">") == 0)
				service.filtrareCheltuieliService(value1, 1, value3);
			else
				service.filtrareCheltuieliService(value1, -1, value3);

	}
}
void UI::undo()
{
	int isFunctionSuccesful = this->service.undoService();
	if (isFunctionSuccesful == -1)
		cout << "No more undos!\n";
}
