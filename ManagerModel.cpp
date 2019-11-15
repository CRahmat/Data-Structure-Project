#include "ManagerModel.h"
#include <stdlib.h> // Malloc
#include <iostream>
using std :: cout;
//Default Constructor
ManagerModel::ManagerModel()
{
}
				//Struct Client Account[Link List]
		typedef struct linkListAdmin *typeptr;
		struct linkListAdmin{
			ManagerModel :: AdminAccount adminAccounts;
			typeptr next;
			typeptr prev;
		};
		typeptr begin, last;			
void ManagerModel :: insertAdminAccount(string pIDAdmin, string pPIN, string pName, string pNoKTP, string pNoTelp){	
	//Temp Struct clients
	AdminAccount Temp;
	//Input parameters ke struct
	Temp.name = pName;
	Temp.noKTP = pNoKTP;
	Temp.noTelp = pNoTelp;
	Temp.PIN = pPIN;
	Temp.IDAdmin = pIDAdmin;
	//Mengirim Struct ke Link List
	inputList(Temp);
}
		//Link List Kosong
		int ManagerModel :: emptyList(){
			if(begin == NULL && last == NULL){
				return true;
			}else{
				return false;
			}	
		};
		//Buat Link List
		void ManagerModel :: createList(){
			typeptr List;
			List = (linkListAdmin *)malloc(sizeof(linkListAdmin));
			List = NULL;
			begin = List;
			last = List;	
		};
		//Input Link List
		void ManagerModel :: inputList(AdminAccount pAdminAccount){
			//Variable bantu dengan type pointer
			typeptr help;
			help = (linkListAdmin *)malloc(sizeof(linkListAdmin));
			help -> adminAccounts = pAdminAccount;
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
					if(check -> adminAccounts.IDAdmin == pAdminAccount.IDAdmin){
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
		void ManagerModel :: deleteList(string IDAdmin, string PIN){
			if(emptyList()){
				cout << "List Kosong";
			}else{
				if(begin -> adminAccounts.IDAdmin == IDAdmin && begin -> adminAccounts.PIN == PIN){
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
				else if(last -> adminAccounts.IDAdmin == IDAdmin && last -> adminAccounts.PIN == PIN){
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
				if(check -> adminAccounts.IDAdmin == IDAdmin && check -> adminAccounts.PIN == PIN){
					result = true;
				}
				check = check -> next;
			}
			if(result == true){
				check = begin;
				while(check -> next -> adminAccounts.IDAdmin == IDAdmin && check -> next -> adminAccounts.PIN == PIN ){
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
		void ManagerModel :: list(){
			typeptr help;
			help = begin;
			while(help -> next != NULL){
				help = help -> next;
			}
		};
