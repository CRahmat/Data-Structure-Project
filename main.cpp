#include <iostream>
#include <windows.h>
#include "MainMenu.h"
#include "Loading.h"
using namespace std;
int main()
{
	Loading(75,20);
	system("CLS");
	MainMenu * mainMenu;
	mainMenu = new MainMenu();
	
} //Main
