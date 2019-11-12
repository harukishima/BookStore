#include "Account.h"

void Account::setName(string& name)
{
	mName = name;
}

void Account::setPass(string& pass)
{
	mPass = pass;
}

void Account::setType(const int& type)
{
	mType = type;
}

string Account::getName()
{
	return mName;
}

string Account::getPass()
{
	return mPass;
}

int Account::getType()
{
	return mType;
}