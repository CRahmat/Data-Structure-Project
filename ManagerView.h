#ifndef MANAGERVIEW_H
#define MANAGERVIEW_H
#include <iostream>
using namespace std;
class ManagerView
{
	public:
		ManagerView();
		void createAccount();
		void deleteAccount();
		void updateAccount();
		void listAccount();
		void transactionHistory();
		void deposito();
		string getName();
		string getAddress();
		string getBirthDay();
		string getNoKTP();
		string getNoTelp();
		string getUsername();
		string getPIN();
		void setNama();
		void setAddress();
		void setBirthDay();
		void setNoKTP();
		void setNoTelp();
		void setUsername();
		void setPIN();
		private :
			string name;
			string address;
			string birthDay;
			string noKTP;
			string noTelp;
			string username;
			string PIN;
			string companyID;
};

#endif
