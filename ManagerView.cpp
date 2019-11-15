#include "ManagerView.h"
#include "Position.h"
#include "MainMenu.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <mmsystem.h>
using namespace std;
ManagerView::ManagerView()
{
	    int menu = 1;
    enum menu {CREATE =1,LIST, UPDATE, DELETES};
    do{
    bool running = true;
    int x = 13;
    Position(54,13);
    cout<<"-->"; //Posisi Awal Tombol Panah Pada Menu Pertama (MIN) dan menu terakhir(MAX)
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
            cout<<"| LIST ACCOUNT"<<setfill(' ')<<setw(45) <<"|";
            Position(57,16);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,17);
            cout<<"| DELETE ACCOUNT"<<setfill(' ')<<setw(43) <<"|";
            Position(57,18);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,19);
            cout<<"| UPDATE ACCOUNT"<<setfill(' ')<<setw(43) <<"|";
            Position(57,20);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,23);
            cout<<" KEY FUNCTION INFO:";
            Position(57,24);
            cout<<"+"<<setw(58)<<setfill('-')<<"+";
            Position(57,25);
            cout<<"| ESC  = BACK"<<setfill(' ') <<setw(46) <<"|";
            Position(57,26);
            cout<<"| DOWN = SELECT"<<setfill(' ')<<setw(37)<<"UP = SELECT "<<setw(7)<<"|";
            Position(57,27);
            cout<<"+"<<setw(58)<<setfill('=')<<"+";
            system("PAUSE>NUL"); //Pause Tanpa Pesan
            system("CLS");
            if(GetAsyncKeyState(VK_DOWN)) // Action ketika arah bawah di KLIK
            {
            	PlaySound(TEXT("SoundEffect.wav"), NULL, SND_SYNC);
                Position(54,x);
                cout<<"   ";
                x+=2;
                if(x > 20)
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
            running = false;
            system("CLS");
            Position(57,8);
            cout << "+"<<setw(58)<<setfill('-')<<"+";
            Position(57,9);
            cout << "|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|";
            Position(57,10);
            cout << "|" << setfill(' ') << setw(30) << "MANAGER MENU" <<setfill(' ')<<setw(28) << "|";
            Position(57,11);
            cout << "|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|";
            Position(57,12);
            cout << "+"<<setw(58)<<setfill('-')<<"+";
            Position(70,14);
            cout << "  KODE PERUSAHAAN  : "; cin >> companyID;
            if(companyID == "124180026" || companyID == "124180025" ){
    		system("CLS");
            	
                switch(menu)
                {
                case CREATE :
                {
                	system("CLS");
                    running = false;
                    createAccount();
                    break;
                };
                case LIST :
                {
                	system("CLS");
                    running = false;
                    listAccount();
                    break;
                };
                case UPDATE :
                {
                	system("CLS");
                    running = false;
                    updateAccount();
                    break;
                };
                case DELETES :
                {
                	system("CLS");
                    running = false;
                    deleteAccount();
                    break;
                };
                }
            }else{
            Position(65,14);
            cout << "KODE PERUSAHAAN YANG ANDA MASSUKAN SALAH\n";
            Position(45,15);
            system("PAUSE>NUL");
            system("CLS");
                MainMenu* mainMenu;
            	mainMenu = new MainMenu();
			}
            }
        }
    }while(menu > 0 && menu < 5);
}

void ManagerView :: createAccount(){
	        cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
            cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
            cout<<"|" << setfill(' ') << setw(35) << "CREATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
            cout<<"+"<<setw(58)<<setfill('-')<<"+\n";cin.ignore();
            cout<<" Nama\t\t: ";getline(cin, name);cout << endl;
            cout<<" No.KTP\t\t: ";getline(cin, noKTP);cout << endl;
            cout<<" No.Telephon\t: ";getline(cin, noTelp);cout << endl;
            cout<<" ID Admin\t: ";getline(cin, username);cout << endl;
            cout<<" PIN\t\t: ";getline(cin, PIN);cout << endl;
}
void ManagerView :: deleteAccount(){
		    cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
            cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
            cout<<"|" << setfill(' ') << setw(35) << "DELETE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
            cout<<"+"<<setw(58)<<setfill('-')<<"+\n";cin.ignore();
            cout<<" ID Admin\t: ";getline(cin, username);cout << endl;
            cout<<" PIN\t\t: ";getline(cin, PIN);cout << endl;
	
}
void ManagerView :: listAccount(){
			cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
            cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
            cout<<"|" << setfill(' ') << setw(35) << "LIST   ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
            cout<<"+"<<setw(58)<<setfill('-')<<"+\n";cin.ignore();
            cout<<" ID Admin\t: ";getline(cin, username);cout << endl;
            cout<<" PIN\t\t: ";getline(cin, PIN);cout << endl;
	
}
void ManagerView :: updateAccount(){
			cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
            cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
            cout<<"|" << setfill(' ') << setw(35) << "UPDATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
            cout<<"+"<<setw(58)<<setfill('-')<<"+\n";cin.ignore();
            cout<<" ID Admin\t: ";getline(cin, username);cout << endl;
            cout<<" PIN\t\t: ";getline(cin, PIN);cout << endl;
	
}
