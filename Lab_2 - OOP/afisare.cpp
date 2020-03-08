#include <iostream>
using namespace std;

void afisare(int n, int v[100], int start, int sfarsit)
{
	for (int i = start; i <= sfarsit; i++)
		cout << v[i] << " ";
	cout << endl;
}
