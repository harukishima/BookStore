#ifndef __MANGHOADON_H__
#define __MANGHOADON_H__

#include"HoaDon.h"
#include<vector>
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
};





#endif // !__MANGHOADON_H__

