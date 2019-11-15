#include "Loading.h"
#include "Position.h"
#include <iostream>
#include <windows.h>
using std :: cout;
Loading::Loading(int x, int y)
{
	this-> x = x;
	this-> y = y;
	for(int i = 0; i < 101 ; i++){
		system("COLOR 09");
		if(i < 30){
		Position(x,y);cout<<"Loading...........";
		Position((x+18),y);cout<<i<<"%";
		Sleep(5);	
		}
		else if(i < 60 && i > 30){
		Position((x-5),y);cout<<"Loading Data...........";
		Position((x+18),y);cout<<i<<"%";
		Sleep(20);
		}
		else if(i < 97 && i > 60){
		Position((x-5),y);cout<<"Verifikasi Data...........";
		Position((x+18),y);cout<<i<<"%";
		Sleep(40);	
		}
		else if(i >97 && i < 101){
		Position((x-5),y);cout<<"Verifikasi Data...........";
		Position((x+18),y);cout<<i<<"%";
		Sleep(1000);	
		}
	}

}
