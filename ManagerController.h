#ifndef MANAGERCONTROLLER_H
#define MANAGERCONTROLLER_H
#include "ManagerModel.h"
#include "ManagerView.h"

class ManagerController
{
	public:
		ManagerController(ManagerView , ManagerModel);
		ManagerModel managerModel;
		ManagerView managerView;
	protected:
};

#endif
