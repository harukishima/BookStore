#ifndef __SACH_H__
#define __SACH_H__
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Sach
{
private:
	string ID;
	string TENSACH;
	string TACGIA = "";
	string NXB = "";
	//int hidden = 0; //0: no hide, 1: only admin and publisher, 2: only admin and author, 3: only admin, publisher and author, 4: only admin
	
	int GIASACH;
public:
	vector<string> blackList;
	bool hidUser = false, hidPublisher = false, hidAuthor = false;
	Sach();
	Sach(string, string, int);
	Sach(const Sach&);
	~Sach();
	Sach& operator=(const Sach&);
	friend ostream& operator<<(ostream& out, Sach s);
	void fSetID(string id);
	void fSetName(string tensach);
	void fSetGia(int giasach);
	void fSetTacGia(string tacgia);
	void fSetNXB(string nxb);
	void fNhapSach();
	string fGetID();
	string fGetName();
	string fGetTacGia();
	string fGetNXB();
	int fGetGia();
	void inSach();
	bool checkBlackList(const string&);
};


#endif // !__SACH_H__