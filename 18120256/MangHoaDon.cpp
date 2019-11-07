#include "MangHoaDon.h"



MangHoaDon::MangHoaDon()
{
}


MangHoaDon::~MangHoaDon()
{
}

int MangHoaDon::getTongTien()
{
	return mTongTien;
}

void MangHoaDon::themHoaDon(HoaDon& hd)
{
	if (hd.getTien() == -1)
	{
		return;
	}
	mHoaDon.push_back(hd);
	mTongTien += hd.getTien();
}

void MangHoaDon::themHoaDon()
{
	
}

void MangHoaDon::inMHoaDon()
{
	if (mHoaDon.empty()) return;
	cout << "STT\tTen sach\tDonGia\tSo luong\tTong\n";
	for (int i = 0; i < mHoaDon.size(); i++)
	{
		cout << i+1 << "\t" << mHoaDon[i] << endl;
	}
	cout << "Tong tien: \t\t\t\t" << mTongTien;
}

void MangHoaDon::xoaHoaDon()
{
	inMHoaDon();
	cout << "Nhap STT hoa don can xoa: ";
	int i;
	cin >> i;
	if (i < 0 || i > mHoaDon.size())
	{
		cout << "Ngoai pham vi" << endl;
		return;
	}
	vector<HoaDon>::iterator it;
	int count = 0;
	for (it = mHoaDon.begin(); it != mHoaDon.end(); it++)
	{
		count++;
		if (count == i)
		{
			mHoaDon.erase(it);
			break;
		}
	}
}

void MangHoaDon::suaHoaDon()
{
	inMHoaDon();
	cout << "Nhap STT hoa don can sua: ";
	int i;
	cin >> i;
	if (i < 0 || i > mHoaDon.size())
	{
		cout << "Ngoai pham vi" << endl;
		return;
	}
	int soLuong;
	cout << "Nhap so luong moi: ";
	cin >> soLuong;
	int donGia = mHoaDon[i - 1].getTien() / mHoaDon[i - 1].getSoLuong();
	mHoaDon[i - 1].setSoLuong(soLuong);
	mHoaDon[i - 1].setTien(donGia * mHoaDon[i - 1].getSoLuong());
	capNhatTongTien();
}

void MangHoaDon::capNhatTongTien()
{
	vector<HoaDon>::iterator it;
	int S = 0;
	for (it = mHoaDon.begin(); it != mHoaDon.end(); it++)
	{
		S += it->getTien();
	}
	mTongTien = S;
}

void MangHoaDon::xoaTatCaHoaDon()
{
	mHoaDon.clear();
	mTongTien = 0;
}
