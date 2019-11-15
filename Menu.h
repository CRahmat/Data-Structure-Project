#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;
class Menu
{
	public:
		Menu();
		void adminMenu();
		void clientMenu();
		void infoMenu();
		~Menu();
	private : 
		string tempIDAdmin;
		string tempPassword;	
};

#endif
