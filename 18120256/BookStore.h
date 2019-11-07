#ifndef __BOOKSTORE_H__
#define __BOOKSTORE_H__

#include"Menu.h"
#include"ListSach.h"
#include"Guest.h"
#include"User.h"
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;


class BookStore
{
private:
	bool isRun;
	bool isLogged;
	int type;
	Menu menu;
	ListSach Ke1;
	vector<User> listUser;
	User* curU;
	Guest guest;
public:
	BookStore();
	virtual ~BookStore() = default;
	void run();
	void loadUserList(const string&);
	void loadBookList(const string&);
	User splitUserLine(string, char);
	Sach splitBookLine(string, char);
	void guessFunction(int);
	void userFunction(int);
	void dangNhap();
};


#endif // !__BOOKSTORE_H__