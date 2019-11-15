#ifndef MANAGERMODEL_H
#define MANAGERMODEL_H
#include <iostream>
using std :: string;
class ManagerModel
{
	public:
		ManagerModel();
		struct AdminAccount{
			string name;
			string noKTP;
			string noTelp;
			string IDAdmin;
			string PIN;
		};
		AdminModel();
		void insertAdminAccount(string = "", string = "", string = "", string = "", string = "");
		int emptyList();
		void createList();
		void inputList(AdminAccount);
		void deleteList(string, string);
		void list();
};

#endif
