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

void MangHoaDon::setDiscount(float dis)
{
	discount = dis;
}

float MangHoaDon::getDiscount()
{
	return discount;
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
	capNhatTongTien();
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
	mTongTien = S - discount * S;
}

void MangHoaDon::xoaTatCaHoaDon()
{
	mHoaDon.clear();
	mTongTien = 0;
}

void MangHoaDon::loadBill(const string& path, ListSach& Ke)
{
	ifstream file(path);
	if (!file.is_open())
	{
		//cout << "Khong load duoc hoa don" << endl;
		return;
	}
	string line;
	while (getline(file, line))
	{
		HoaDon newBill = splitBillLine(line, ',', Ke);
		themHoaDon(newBill);
	}
	file.close();
}

void MangHoaDon::exportBill(const string& path)
{
	ofstream file(path);
	if (!file.is_open()) return;
	vector<HoaDon>::iterator it;
	for (it = mHoaDon.begin(); it != mHoaDon.end(); it++)
	{
		file << it->mSach.fGetID() << "," << it->getSoLuong() << endl;
	}
	file.close();
}

HoaDon MangHoaDon::splitBillLine(string line, char delim, ListSach& Ke)
{
	stringstream str(line);
	string tmp;
	getline(str, line, delim);
	Sach newBook = *Ke.findBookBaseOnID(tmp);
	HoaDon newBill;
	newBill.setBook(newBook);
	getline(str, line, delim);
	newBill.setSoLuong(stod(tmp));
	newBill.setTien(newBook.fGetGia() * newBill.getSoLuong());
	return newBill;
}
