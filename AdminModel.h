#ifndef ADMINMODEL_H
#define ADMINMODEL_H
#include <string>
using std :: string;
class AdminModel
{
	public:
		struct ClientAccount{
			string name;
			string address;
			string birthDay;
			string noKTP;
			string noTelp;
			string username;
			string PIN;
		};
		AdminModel();
		void insertClientAccount(string = "", string = "", string = "", string = "", string = "", string = "", string = "");
		int emptyList();
		void createList();
		void inputList(ClientAccount);
		void deleteList(string, string);
		void list();
};

#endif
