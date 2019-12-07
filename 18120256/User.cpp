#include "User.h"



User::User()
{
	mType = 1;
}

User::User(string user, string pass, string name, int age)
{
	mType = 1;
	mUsername = user;
	mPass = pass;
	mName = name;
	mAge = age;
}


User::~User()
{
}



void User::setDiscount(float dis)
{
	mHoadon.setDiscount(dis);
}

void User::setAge(const int& age)
{
	mAge = age;
}



int User::getAge()
{
	return mAge;
}



void User::muaSach(ListSach& ke)
{
	HoaDon tmp;
	tmp.taoHoaDon(ke);
	mHoadon.themHoaDon(tmp);
}

void User::capNhatDonHang()
{
	cout << "1. Xoa hoa don" << endl;
	cout << "2. Sua hoa don" << endl;
	cout << "3. Don sach don hang" << endl;
	int chon;
	cin >> chon;
	switch (chon)
	{
	case 1:
		mHoadon.xoaHoaDon();
		break;
	case 2:
		mHoadon.suaHoaDon();
		break;
	case 3:
		mHoadon.xoaTatCaHoaDon();
		break;
	default:
		break;
	}
}

void User::inDanhSachHoaDon()
{
	mHoadon.inMHoaDon();
}

void User::loadBill(ListSach& Ke)
{ 
	string path = "Bill\\" + mUsername + ".csv";
	mHoadon.loadBill(path, Ke);
}

void User::exportBill()
{
	string path = "Bill\\" + mUsername + ".csv";
	mHoadon.exportBill(path);
}

void User::printInformation()
{
	cout << "Ten dang nhap: " << mUsername << endl;
	cout << "Ten: " << mName << endl;
	cout << "Tuoi: " << mAge << endl;
}

ostream& operator<<(ostream& out, User scr)
{
	out << scr.mType << "," << scr.mUsername << "," << scr.mPass << "," << scr.mName << "," << scr.mAge;
	return out;
}
