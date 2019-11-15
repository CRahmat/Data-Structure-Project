#include "AdminView.h"
#include "AdminModel.h"
#include <iostream>
#include <iomanip>
using namespace std;
AdminView::AdminView()
{
	
}

void AdminView :: createAccount(){
            cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
            cout<<"|" << setfill(' ') << setw(41) << "BANKING SYSTEM APPLICATION" <<setfill(' ')<<setw(17) << "|\n";
            cout<<"|" << setfill(' ') << setw(35) << "CREATE ACCOUNT" <<setfill(' ')<<setw(23) << "|\n";
            cout<<"|" << setfill(' ') << setw(47) <<"Jl.Veteran No.45, Babasari, Yogyakarta" << setw(11) << "|\n";
            cout<<"+"<<setw(58)<<setfill('-')<<"+\n";
            cout<<" Nama\t\t: ";getline(cin, name);cout << endl;
            cout<<" Alamat\t: ";getline(cin, address);cout << endl;
            cout<<" Tanggal Lahir\t: ";getline(cin, birthDay);cout << endl;cin.ignore();
            cout<<" No.KTP\t: ";getline(cin, noKTP);cout << endl;cin.ignore();
            cout<<" No.Telephon\t: ";getline(cin, noTelp);cout << endl;cin.ignore();
            cout<<" Username\t:";getline(cin, username);cout << endl;
            cout<<" PIN\t\t: ";getline(cin, PIN);cout << endl;cin.ignore();
}
string AdminView :: getName(){	
	return name;;
}
string AdminView :: getAddress(){
	return  address;
}
string AdminView :: getBirthDay(){
	return birthDay;
}
string AdminView :: getNoKTP(){
	return noKTP;
}
string AdminView :: getNoTelp(){
	return noTelp;
}
string AdminView :: getUsername(){
	return username;
}
string AdminView :: getPIN(){
	return PIN;
}

void AdminView :: deleteAccount(){
}
void AdminView :: updateAccount(){
	
}
void AdminView :: listAccount(){
	
}
void AdminView :: deposito(){
	
}
void AdminView :: transactionHistory(){
	
}
AdminView::~AdminView()
{
}
