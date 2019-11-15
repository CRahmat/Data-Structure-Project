#include "ManagerController.h"
#include "ManagerModel.h"
#include "ManagerView.h"
ManagerController :: ManagerController( ManagerView, ManagerModel){
		this-> managerModel = managerModel;
		this-> managerView = managerView;
		string name = managerView.getName();
		string noKTP = managerView.getNoKTP();
		string noTelp = managerView.getNoTelp();
		string IDAdmin = managerView.getUsername();
		string PIN = managerView.getPIN();
		managerModel.insertAdminAccount(IDAdmin,PIN,name,noKTP,noTelp);
}
