#ifndef __BOOKSTORE_H__
#define __BOOKSTORE_H__

#include"Menu.h"
#include"ListSach.h"
#include"Guest.h"
#include"User.h"
#include"Account.h"
#include"Author.h"
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

#include"Admin.h"

class BookStore
{
private:
	bool isRun;
	bool isLogged;
	int type;
	Menu menu;
	ListSach Ke1;
	list<User> uList;
	list<NXB> pList;
	list<Author> aList;
	list<Admin> adList;
	User* curU = NULL;
	NXB* curP = NULL;
	Author* curA = NULL;
	Admin* curAd = NULL;
	Guest guest;
	Admin QTV;
public:
	BookStore();
	virtual ~BookStore();
	void run();
	void loadUserList(const string&);
	void exportUserList(const string&);
	void loadBookList(const string&);
	void loadPublisherList(const string&);
	void exportPublisherList(const string&);
	void loadBookToPointerList();
	void loadAuthorList(const string&);
	void exportAuthorList(const string&);
	User splitUserLine(string, char);
	NXB splitPublisherLine(string, char);
	Author splitAuthorLine(string, char);
	Sach splitBookLine(string, char);
	void guestFunction(int);
	void userFunction(int);
	void adminFunction(int);
	void dangNhap();
	void dangKi();
	void dangXuat();
	friend class Admin;
};


#endif // !__BOOKSTORE_H__