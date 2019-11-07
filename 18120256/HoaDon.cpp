#include "HoaDon.h"



HoaDon::HoaDon()
{
}


HoaDon::~HoaDon()
{
}

int HoaDon::getSoLuong()
{
	return mSoLuong;
}

int HoaDon::getTien()
{
	return mTien;
}

void HoaDon::setSoLuong(int n)
{
	mSoLuong = n;
}

void HoaDon::setTien(int tien)
{
	mTien = tien;
}

void HoaDon::taoHoaDon(ListSach l, string tensach, int soluong)
{
	 mSach = *l.findBook(tensach);
	 if (mSach.fGetID() == "")
	 {
		 cout << "Khong tim thay sach" << endl;
	 }
	 mTien = mSach.fGetGia()*soluong;
	 mSoLuong = soluong;
}

void HoaDon::taoHoaDon(ListSach l)
{
	string tensach;
	cout << "Tao hoa don" << endl;
	cout << "Nhap ten sach: ";
	cin >> tensach;
	int soluong;
	cout << "So luong: ";
	cin >> soluong;
	mSach = *l.findBook(tensach);
	if (mSach.fGetID() == "")
	{
		cout << "Khong tim thay sach" << endl;
	}
	mTien = mSach.fGetGia() * soluong;
	mSoLuong = soluong;
}

ostream& operator<<(ostream& out, HoaDon& l)
{
	out << l.mSach.fGetName() << "\t\t" << l.mSach.fGetGia() << "\t" << l.getSoLuong() << "\t\t" << l.getTien();
	return out;
}
