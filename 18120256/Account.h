#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <string>
using namespace std;

class Account
{
protected:
	string mName;
	string mPass;
	int mType;
public:
	void setName(string&);
	void setPass(string&);
	void setType(const int&);
	string getName();
	string getPass();
	int getType();
};





#endif // !__ACCOUNT_H__