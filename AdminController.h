#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include "AdminModel.h"
#include "AdminView.h"
class AdminController
{
	public :
		AdminController(AdminView , AdminModel);
		AdminModel adminModel;
		AdminView adminView;
		
};

#endif
