#include "MainMenu.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <mmsystem.h>
#include "Menu.h"
#include "Position.h"
#include "ManagerView.h"
#include "AdminView.h"
MainMenu::MainMenu()
{
	bool running = true; //Default running = true
    int x = 13; //Koordinat Posisi Awal Tanda Panah
    int mainMenu = 1;
    int adminMenu;
    enum mainMenu {ADMIN = 1, CLIENT, INFO };
	Position(54,13);
    cout<<"-->";
    Menu* menu; //Pointer
    menu = new Menu(); //Instansiasi Object Menu.h
    do
    {
    	adminMenu = 0;
    	system("COLOR 09");
        while(running)
        {
            Position(57,9);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,10);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            Position(57,11);
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            Position(57,12);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,13);
            cout<<"| ADMIN"<<setfill(' ')<<setw(52) <<"|";
            Position(57,14);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,15);
            cout<<"| CLIENT/CUSTOMER"<<setfill(' ')<<setw(42) <<"|";
            Position(57,16);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,17);
            cout<<"| INFO"<<setfill(' ')<<setw(53) <<"|";
            Position(57,18);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,20);
            cout<<" KEY FUNCTION INFO:";
            Position(57,21);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,22);
            cout<<"|" << setfill(' ') << setw(32)<<"ESC = EXIT" <<setfill(' ') <<setw(26) <<"|";
            Position(57,23);
            cout<<"| DOWN = SELECT"<<setfill(' ')<<setw(37)<<"UP = SELECT "<<setw(7)<<"|";
            Position(57,24);
            cout<<"+"<<setw(58)<<setfill('=')<<"+";
            Position(87,24);system("PAUSE>NUL"); //Pause Tanpa Pesan
            if(GetAsyncKeyState(VK_DOWN)) // Action ketika arah bawah di KLIK
            {
            	PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                Position(54,x);
                cout<<"   ";
                x+=2; //Memindahkan Posisi Panah
                if(x > 18)
                {
                    x = 13;
                    Position(54,13);//Jika panah pada menu terakhir akan kembali ke menu pertama
                    cout<<"-->";
                    mainMenu = ADMIN; //Main Menu = 1 (enum ADMIN)
                }
                else
                {
                    Position(54,x);//Jika panah masih berada di menu
                    cout<<"-->";
                    mainMenu++;//Menyesesuaikan Menu
                }
            }
            else if(GetAsyncKeyState(VK_UP))
            {
            	PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                Position(54,x);
                cout<<"   ";
                x-=2; //Memindahkan Posisi Panah
                if(x < 12)
                {
                    x = 17;
                    Position(54,17);//Jika panah pada menu pertama akan kembali ke menu terakhir
                    cout<<"-->";
                    mainMenu=INFO; //Main Menu = 3 (enum INFO)
                }
                else
                {
                    Position(54,x);
                    cout<<"-->";
                    mainMenu--;
                }
            }
            else if(GetAsyncKeyState(VK_ESCAPE) ){ //Action saat buttom ESC di tekan
            PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
            	system("CLS");
            	exit(0);
			}
			else if(GetAsyncKeyState(VK_SPACE)){
				adminMenu++;
				Position(54,x);
                cout<<"-->";
				if(adminMenu == 3){
					system("CLS");
					running = false;
					ManagerView * managerView;
					managerView = new ManagerView();
				}
			}
            else if(GetAsyncKeyState(VK_RETURN))
            {
            	system("CLS");
                switch(mainMenu)
                {
                case ADMIN :
                {
                    running = false;// Memberhentikan Perulangan While
                    menu->adminMenu(); //Pemanggilan Method adminMenu pada Class Menu
                    break;
                };
                case CLIENT :
                {
                    running = false;// Memberhentikan Perulangan While
                    menu->clientMenu(); //Pemanggilan Method clientMenu pada Class Menu
                    break;
                };
                case INFO :
                {
                    running = false; // Memberhentikan Perulangan While
                    menu->infoMenu(); //Pemanggilan Method clientMenu pada Class Menu
                    break;
                };
                } //SWITCH
            } //If VK_RETURN
        	else //Action saat ditekan selain tombol di atas
            {
                Position(54,x); //Jika Di tekan Selain Tombol Atas  Posisi Panah Tetap
                cout<<"-->";
            }
        } //WHILE
    }while(mainMenu == ADMIN || CLIENT || INFO);
}
