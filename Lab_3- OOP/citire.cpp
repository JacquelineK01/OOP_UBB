#include <iostream>
using namespace std;

void citire(int& n, int v[])
{
	cout << "Dati marimea sirului: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
		{ cout<<"v["<<i<<"]="; cin >> v[i];}
}
