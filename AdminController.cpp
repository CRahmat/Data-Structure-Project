#include "AdminController.h"
#include "AdminModel.h"
#include "AdminView.h"
AdminController :: AdminController(AdminView aminView, AdminModel adminModel)
{
		this-> adminModel = adminModel;
		this-> adminView = adminView;
		string name = adminView.getName();
		string address = adminView.getAddress();
		string birthDay = adminView.getBirthDay();
		string noKTP = adminView.getNoKTP();
		string noTelp = adminView.getNoTelp();
		string username = adminView.getUsername();
		string PIN = adminView.getPIN();
		adminModel.insertClientAccount(username,PIN,name,address,birthDay,noKTP,noTelp);
}
