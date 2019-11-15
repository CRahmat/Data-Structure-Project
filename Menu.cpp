#include <iostream> // Input and Output
#include <windows.h> // PAUSE, CLS, and Position
#include <iomanip> //Setw() and Setfill()
#include <cstdlib> //Random
#include <stdlib.h>
#include <mmsystem.h>
#include "Menu.h"
#include "MainMenu.h"
#include "Position.h"
using namespace std;
Menu::Menu()
{
}

void Menu :: adminMenu(){
			Position(57,8);
            cout << "+"<<setw(58)<<setfill('-')<<"+";
            Position(57,9);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            Position(57,10);
            cout << "|" << setfill(' ') << setw(33) << "ADMIN MENU" <<setfill(' ')<<setw(25) << "|";
            Position(57,11);
            cout << "|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            Position(57,12);
            cout << "+"<<setw(58)<<setfill('-')<<"+";
            Position(70,14);
            cout << "  ID ADMIN  : "; getline(cin, tempIDAdmin);
            Position(70,16);
            cout << "  PASSWORD  : "; getline(cin, tempPassword);
            Position(57,18);
            cout << "+"<<setw(58)<<setfill('-')<<"+";
    		//Loading
    		system("CLS");
    int x = 13;
    bool running = true;
    int menu = 1;
    enum menu {CREATE =1,LIST, DEPOSITO, UPDATE, HISTORY, DELETES};
    Position(54,13);
    cout<<"-->"; //Posisi Awal Tombol Panah Pada Menu Pertama (MIN) dan menu terakhir(MAX)
    do
    {
        while(running)
        {
            Position(57,8);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,9);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            Position(57,10);
            cout << "|" << setfill(' ') << setw(32) << "ADMIN MENU" <<setfill(' ')<<setw(26) << "|";
            Position(57,11);
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            Position(57,12);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,13);
            cout<<"| CREATE ACCOUNT"<<setfill(' ')<<setw(43) <<"|";
            Position(57,14);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,15);
            cout<<"| UPDATE ACCOUNT"<<setfill(' ')<<setw(43) <<"|";
            Position(57,16);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,17);
            cout<<"| DELETE ACCOUNT"<<setfill(' ')<<setw(43) <<"|";
            Position(57,18);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,19);
            cout<<"| LIST ACCOUNT"<<setfill(' ')<<setw(45) <<"|";
            Position(57,20);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,21);
            cout<<"| ADD DEPOSITO"<<setfill(' ')<<setw(45) <<"|";
            Position(57,22);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,23);
            cout<<"| HISTORY TRANSACTION"<<setfill(' ')<<setw(38) <<"|";
            Position(57,24);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,26);
            cout<<" KEY FUNCTION INFO:";
            Position(57,27);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,28);
            cout<<"| F1   = DAFTAR ANTRIAN"<<setfill(' ') <<setw(36) <<"|";
            Position(57,29);
            cout<<"| DOWN = SELECT"<<setfill(' ')<<setw(37)<<"UP = SELECT "<<setw(7)<<"|";
            Position(57,30);
            cout<<"+"<<setw(58)<<setfill('=')<<"+";
            system("PAUSE>NUL"); //Pause Tanpa Pesan
            system("CLS");
            if(GetAsyncKeyState(VK_DOWN)) // Action ketika arah bawah di KLIK
            {
            	PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                Position(54,x);
                cout<<"   ";
                x+=2;
                if(x > 24)
                {
                    x = 13;
                    Position(54,13);//Jika x lebih besar dari MAX tanda panah berpindah ke MIN
                    cout<<"-->";
                    menu = CREATE;
                }
                else
                {
                    Position(54,x);//Jika kurang dari maka akan berpindah ke bawah
                    cout<<"-->";
                    menu++;
                }
            }
            else if(GetAsyncKeyState(VK_UP))
            {
            	PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                Position(54,x);
                cout<<"   ";
                x-=2;
                if(x < 12)
                {
                    x = 19;
                    Position(54,19);//Jika x kurang dari dari MIN tandah panah berpindah ke MAX
                    cout<<"-->";
                    menu = DELETES;
                }
                else
                {
                    Position(54,x);
                    cout<<"-->";
                    menu--;
                }
            }
            else if(GetAsyncKeyState(VK_ESCAPE)){
            	PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
            	MainMenu * mainMenu;
            	mainMenu = new MainMenu();
			}
            else
            {
                Position(54,x); //Jika Di tekan Selain Tombol Atas Bawah tanda Panah Tetap
                cout<<"-->";
            }
            if(GetAsyncKeyState(VK_RETURN))
            {
                switch(menu)
                {
                case CREATE :
                {
                	system("CLS");
                    running = false;
                    break;
                };
                case LIST :
                {
                	system("CLS");
                    running = false;
                    break;
                };
                case UPDATE :
                {
                	system("CLS");
                    running = false;
                    break;
                };
                case DELETES :
                {
                	system("CLS");
                    running = false;
                    break;
                };
                }
            }
        }
    }
    while(menu > 0 && menu < 7);
}
void Menu :: clientMenu(){
	bool running = true;
    int x = 13;
    int menu = 1;
    enum menu {SALDO, TRANSFER, WITHDRAW,CHANGE_PIN,HISTORY};
			Position(57,8);
            cout << "+"<<setw(58)<<setfill('-')<<"+";
            Position(57,9);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            Position(57,10);
            cout << "|" << setfill(' ') << setw(33) << "ADMIN MENU" <<setfill(' ')<<setw(25) << "|";
            Position(57,11);
            cout << "|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            Position(57,12);
            cout << "+"<<setw(58)<<setfill('-')<<"+";
            Position(70,14);
            cout << "  USERNAME  : "; getline(cin, tempIDAdmin);
            Position(70,16);
            cout << "  PASSWORD  : "; getline(cin, tempPassword);
            Position(57,19);
            cout << "+"<<setw(58)<<setfill('-')<<"+";
    		system("PAUSE");
    		system("CLS");
    Position(54,13);
    cout<<"-->"; //Posisi Awal Tombol Panah Pada Menu Pertama (MIN) dan menu terakhir(MAX)
    do
    {
        while(running)
        {
            Position(57,8);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,9);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            Position(57,10);
            cout << "|" << setfill(' ') << setw(32) << "CLIENT MENU" <<setfill(' ')<<setw(26) << "|";
            Position(57,11);
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            Position(57,12);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,13);
            cout<<"| CEK SALDO"<<setfill(' ')<<setw(48) <<"|";
            Position(57,14);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,15);
            cout<<"| TRANSFER"<<setfill(' ')<<setw(49) <<"|";
            Position(57,16);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,17);
            cout<<"| WITHDRAW"<<setfill(' ')<<setw(49) <<"|";
            Position(57,18);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,19);
            cout<<"| CHANGE PIN"<<setfill(' ')<<setw(47) <<"|";
            Position(57,20);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,21);
            cout<<"| HISTORY TRANSACTION"<<setfill(' ')<<setw(38) <<"|";
            Position(57,22);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,26);
            cout<<" KEY FUNCTION INFO:";
            Position(57,27);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,28);
            cout<<"| F1   = DAFTAR ANTRIAN"<<setfill(' ') <<setw(36) <<"|";
            Position(57,29);
            cout<<"| DOWN = SELECT"<<setfill(' ')<<setw(37)<<"UP = SELECT "<<setw(7)<<"|";
            Position(57,30);
            cout<<"+"<<setw(58)<<setfill('=')<<"+";
            system("CLS");
            system("PAUSE>NUL"); //Pause Tanpa Pesan
            if(GetAsyncKeyState(VK_DOWN)) // Action ketika arah bawah di KLIK
            {
                Position(54,x);
                cout<<"   ";
                x+=2;
                if(x > 21)
                {
                    x = 13;
                    Position(54,13);//Jika x lebih besar dari MAX tanda panah berpindah ke MIN
                    cout<<"-->";
                    menu = SALDO;
                }
                else
                {
                    Position(54,x);//Jika kurang dari maka akan berpindah ke bawah
                    cout<<"-->";
                    menu++;
                }
            }
            else if(GetAsyncKeyState(VK_UP))
            {
                Position(54,x);
                cout<<"   ";
                x-=2;
                if(x < 12)
                {
                    x = 21;
                    Position(54,21);//Jika x kurang dari dari MIN tandah panah berpindah ke MAX
                    cout<<"-->";
                    menu = HISTORY;
                }
                else
                {
                    Position(54,x);
                    cout<<"-->";
                    menu--;
                }
            }else if(GetAsyncKeyState(VK_ESCAPE)){
            	MainMenu * mainMenu;
            	mainMenu = new MainMenu();
			}
            else
            {
                Position(54,x); //Jika Di tekan Selain Tombol Atas Bawah tanda Panah Tetap
                cout<<"-->";
            }
            if(GetAsyncKeyState(VK_RETURN))
            {
                switch(menu)
                {
                case SALDO :
                {
                	system("CLS");
                    running = false;
                    break;
                };
                case TRANSFER :
                {
                	system("CLS");
                    running = false;
                    break;
                };
                case WITHDRAW :
                {
                	system("CLS");
                    running = false;
                    break;
                };
                case CHANGE_PIN :
                {
                	system("CLS");
                    running = false;
                    break;
                };
                case HISTORY:
                {
                	system("CLS");
                    running = false;
                    break;
                };
                }
            }
        }
    }
    while(menu > 0 && menu < 7);
}
void Menu :: infoMenu(){
	        Position(57,15);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,16);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            Position(57,17);
            cout << "|" << setfill(' ') << setw(32) << "INFO MENU" <<setfill(' ')<<setw(26) << "|";
            Position(57,18);
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
        	Position(57,19);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,20);
            cout << "|" << setfill(' ') << setw(49) << "SILAHKAN HUBUNGI CUSTOMER SERVICE KAMI!!!" <<setfill(' ')<<setw(9) << "|";
            Position(57,21);
            cout << "|" << setfill(' ') << setw(40) << "Telp : (0274) 999 000 11" <<setfill(' ')<<setw(18) << "|";
            Position(57,22);
            cout<<"|" << setfill(' ') << setw(34) <<"TERIMA  KASIH" << setw(24) << "|";
        	Position(57,23);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,24);
            cout<<"|"<<setw(15)<<setfill(' ')<< "ESC = KELUAR" << setw(42) << "HOME = MENU UTAMA    " << "|";
			Position(57,25);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            system("PAUSE>NUL");
            system("CLS");
            if(GetAsyncKeyState(VK_RETURN)){
            	MainMenu * mainMenu;
            	mainMenu = new MainMenu();
			}else{
				Menu :: infoMenu();
			}
}
Menu::~Menu()
{
}
