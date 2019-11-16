#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <string>
using namespace std;

class Account
{
protected:
	string mUsername;
	string mPass;
	string mName;
	int mType;
public:
	Account();
	void setUsername(string&);
	void setPass(string&);
	void setType(const int&);
	void setName(string&);
	string getUsername();
	string getPass();
	int getType();
	string getName();

	virtual void printInformation() = 0;
};





#endif // !__ACCOUNT_H__