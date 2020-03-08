#include <iostream>
using namespace std;
#include "citire.h"
#include "afisare.h"
#include "subsecvcresc.h"
#include "subsecvcifcom.h"
#include "test3.h"

void menu()
{
	cout <<"------------MENIU------------"<<endl;
	cout << "1.Citire"<<endl;
	cout << "2.Afisare" << endl;
	cout << "3.Afisare cea mai lunga secventa de numere strict crescatoare" << endl;
	cout << "4.Afisare cea mai lunga secventa in care elementele de pe pozitii consecutive au cel putin 2 cifre comune " << endl;
	cout << "5.Exit" << endl;
	cout <<"-----------------------------"<<endl;
	cout << "Dati optiunea: " << endl;
}

int main()
{
    int n;
    int* v = new int[100];
    TestLongestConsecutiveSec();
    TestLongestSubsecvCifCom();
    while (true)
	{
		int op; menu();
		cin >> op;
		if (op == 1)
            {
                citire(n,v);
                continue;
            }
		if (op == 2)
            {
                int start = 1;
                afisare(n,v,start,n);
                continue;
            }
        if (op == 3)
            {
                pair<int, int> pereche = LongestConsecutiveSec(n,v);
                afisare(n,v,pereche.first, pereche.second);
                continue;
            }
        if (op == 4)
            {
                pair<int, int> pereche = LongestSubsecvCifCom(n,v);
                afisare(n,v,pereche.first, pereche.second);
                continue;
            }
		if (op == 5) {

                delete[] v;
                break;
		}
		return 0;
	}
}
