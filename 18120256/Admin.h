#ifndef __ADMIN_H__
#define __ADMIN_H__


#include "Account.h"
#include "User.h"
#include "NXB.h"
#include "Author.h"
#include "Discount.h"
#include <list>

class Admin :
	public Account
{
public:
	/*list<User> uList;
	list<NXB> pList;
	list<Author> aList;*/

	Admin();
	
	void printUserList(list<User>&);
	void printPublisherList(list<NXB>&);
	void printAuthorList(list<Author>&);

	bool isNameExist(const string&, list<NXB>&, list<Author>&);
	void blacklist(ListSach&, list<NXB>& pList, list<Author>& aList);
	void discountManagement(Discount& dis);
	void lockBook(ListSach&, bool hid);

	friend ostream& operator<<(ostream& out, Admin scr);

	virtual void printInformation();
};







#endif // !__ADMIN_H__