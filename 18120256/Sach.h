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
	vector<string> blackList;
	int GIASACH;
public:
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

};


#endif // !__SACH_H__