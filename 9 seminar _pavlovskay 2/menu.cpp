#include <iostream>
#include"FloppyDisk.h"
#include "Menu.h"

using namespace std;

void Menu::print_menu()
{
	FloppyDisk FloppyDisk;
	while (true)
	{
		cout << "\n0 - Enter comand. \n1 - Reqvest data. \n2 - Exit\n>";
		char item;
		cin >> item;
		switch (item)
		{
		case '0':
			cout << "Comand: name file  size file  comand(comand 1 - write)(comand 0 - delete)\n>";
			FloppyDisk.comand();
			break;
		case '1':
			FloppyDisk.print_list();
			break;
		case '2':
			exit(0);
			break;
		default:
			cout << "Error not comand!" << endl;
			break;
		}
	}
}