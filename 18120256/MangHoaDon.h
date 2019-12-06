#ifndef __MANGHOADON_H__
#define __MANGHOADON_H__

#include"HoaDon.h"
#include"ListSach.h"
#include<vector>
#include<sstream>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class MangHoaDon
{
private:
	vector<HoaDon> mHoaDon;
	int mTongTien;
public:
	MangHoaDon();
	virtual ~MangHoaDon();
	int getTongTien();
	void themHoaDon(HoaDon&);
	void themHoaDon();
	void inMHoaDon();
	void xoaHoaDon();
	void suaHoaDon();
	void capNhatTongTien();
	void xoaTatCaHoaDon();
	void loadBill(const string&, ListSach& Ke);
	void exportBill(const string&);
	HoaDon splitBillLine(string line, char delim, ListSach& Ke);
};





#endif // !__MANGHOADON_H__

