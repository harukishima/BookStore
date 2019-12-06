#ifndef __HOADON_H__
#define __HOADON_H__

#include"ListSach.h"
#include<string>
#include<vector>
using namespace std;

class HoaDon
{
private:

	int mSoLuong = -1;
	int mTien;
public:
	Sach mSach;
	HoaDon();
	virtual ~HoaDon();

	int getSoLuong();
	int getTien();
	void setSoLuong(int);
	void setTien(int);
	void setBook(Sach);
	void taoHoaDon(ListSach, string tensach, int);
	void taoHoaDon(ListSach);
	friend ostream& operator<<(ostream& out, HoaDon& l);
};



#endif // !__HOADON_H__
