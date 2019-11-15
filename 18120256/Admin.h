#ifndef __ADMIN_H__
#define __ADMIN_H__


#include "Account.h"
#include "User.h"
#include "NXB.h"
#include "Author.h"
#include <list>

class Admin :
	public Account
{
public:
	list<User> uList;
	list<NXB> pList;
	list<Author> aList;

	Admin();
	

};







#endif // !__ADMIN_H__