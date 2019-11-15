#ifndef __AUTHOR_H__
#define __AUTHOR_H__


#include "Account.h"
#include "Sach.h"
#include <vector>
using namespace std;
class Author :
	public Account
{
public:
	vector<Sach*> list;
	Author();
	virtual ~Author() = default;

};









#endif // !__AUTHOR_H__