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
	
	void printUserList();
	void printPublisherList();
	void printAuthorList();

	bool isNameExist(const string&);
	void blacklist(ListSach&);

	virtual void printInformation();
};







#endif // !__ADMIN_H__