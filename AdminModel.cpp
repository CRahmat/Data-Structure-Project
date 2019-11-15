#include "AdminModel.h"
#include <stdlib.h> // Malloc
#include <iostream>
using std :: cout;
//Default Constructor
AdminModel :: AdminModel(){	
}
				//Struct Client Account[Link List]
		typedef struct linkListClient *typeptr;
		struct linkListClient{
			AdminModel :: ClientAccount clientAccounts;
			typeptr next;
			typeptr prev;
		};
		typeptr begin, last;			
void AdminModel :: insertClientAccount(string pUsername, string pPIN, string pName, string pAddress, string pBirthDay, string pNoKTP, string pNoTelp){	
	//Temp Struct clients
	ClientAccount Temp;
	//Input parameters ke struct
	Temp.name = pName;
	Temp.address = pAddress;
	Temp.birthDay =pBirthDay;
	Temp.noKTP = pNoKTP;
	Temp.noTelp = pNoTelp;
	Temp.PIN = pPIN;
	Temp.username = pUsername;
	//Mengirim Struct ke Link List
	inputList(Temp);
}
		//Link List Kosong
		int AdminModel :: emptyList(){
			if(begin == NULL && last == NULL){
				return true;
			}else{
				return false;
			}	
		};
		//Buat Link List
		void AdminModel :: createList(){
			typeptr List;
			List = (linkListClient *)malloc(sizeof(linkListClient));
			List = NULL;
			begin = List;
			last = List;	
		};
		//Input Link List
		void AdminModel :: inputList(ClientAccount pClientAccount){
			//Variable bantu dengan type pointer
			typeptr help;
			help = (linkListClient *)malloc(sizeof(linkListClient));
			help -> clientAccounts = pClientAccount;
			begin -> next = NULL;
			begin -> prev = NULL;
			if(emptyList()){
				begin = help;
				last = begin;
			}else{
				typeptr check;
				bool result = false;
				check = begin;
				while(check -> next != NULL ){
					if(check -> clientAccounts.username == pClientAccount.username){
						result = true;
					}
					check = check -> next;
				}
				if(result == true){
				if(last == begin){
				last = help;
				last -> prev = begin;
				begin -> next = last;
				}else{
					last -> next = help;
					help -> prev = last;
					last = help;
				}
			}else {
				cout << "Your Account Already Used !!!\n";
			}
			}	
		};
		void AdminModel :: deleteList(string username, string PIN){
			if(emptyList()){
				cout << "List Kosong";
			}else{
				if(begin -> clientAccounts.username == username && begin -> clientAccounts.PIN == PIN){
					typeptr help;
					help = begin;
					if(last == begin){
						free(help);
						begin = NULL;
						last = begin;
					}else{
					begin = help -> next;
					free(help);
					begin -> prev = NULL;	
					}
				}
				else if(last -> clientAccounts.username == username && last -> clientAccounts.PIN == PIN){
					typeptr help, tempDelete;
					help = begin;
					while(help -> next != last){
						help = help -> next;
					}
					tempDelete = help -> next;
					last = help;
					free(tempDelete);
					last -> next = NULL;
				}else{
			typeptr check, tempDelete;
			check = begin;
			bool result = false;
			//Data Hanya 3
			while (check -> next != last ){
				if(check -> clientAccounts.username == username && check -> clientAccounts.PIN == PIN){
					result = true;
				}
				check = check -> next;
			}
			if(result == true){
				check = begin;
				while(check -> next -> clientAccounts.username == username && check -> next -> clientAccounts.PIN == PIN ){
					check = check -> next;
				}
				tempDelete = check -> next;
				check -> next = tempDelete -> next;
				tempDelete -> next -> prev = check;
				free(tempDelete);
				
				
				
			}	
				}
			}
		};
		void AdminModel :: list(){
			typeptr help;
			help = begin;
			while(help -> next != NULL){
				help = help -> next;
			}
		};
