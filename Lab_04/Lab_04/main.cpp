#pragma once
#include <iostream>
#include "UI.h"
#include "Tests.h"
int main() {
	Repo repo;
	cout << 1;
	Service service(repo);
	cout << 2;
	UI ui(service);
	cout << 3;
	runTests();
	ui.start();
	return 0;
}