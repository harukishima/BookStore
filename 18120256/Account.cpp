#include "Account.h"

Account::Account()
{
	mUsername = mPass = mName = "";
	mType = -1;
}

void Account::setUsername(string& name)
{
	mUsername = name;
}

void Account::setPass(string& pass)
{
	mPass = pass;
}

void Account::setType(const int& type)
{
	mType = type;
}

void Account::setName(string& name)
{
	mName = name;
}

string Account::getUsername()
{
	return mUsername;
}

string Account::getPass()
{
	return mPass;
}

int Account::getType()
{
	return mType;
}

string Account::getName()
{
	return mName;
}

void Account::sendMessage(const string& receiver)
{
	cin.ignore();
	string message;
	cout << "Tin nhan: ";
	getline(cin, message);
	Messager::sendMessage(mUsername, receiver, message);
}

void Account::viewInbox()
{
	Messager::inbox(mUsername);
}
