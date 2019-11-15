#ifndef ADMINVIEW_H
#define ADMINVIEW_H
#include "AdminModel.h"
using namespace std;
class AdminView
{
		public:
		AdminView();
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
		~AdminView();

};

#endif
