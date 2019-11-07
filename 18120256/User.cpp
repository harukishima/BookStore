#include "User.h"



User::User()
{
}


User::~User()
{
}

void User::setName(string& name)
{
	mName = name;
}

void User::setPass(string& pass)
{
	mPass = pass;
}

void User::setAge(const int& age)
{
	mAge = age;
}

void User::setType(const int& type)
{
	mType = type;
}

string User::getName()
{
	return mName;
}

string User::getPass()
{
	return mPass;
}

int User::getAge()
{
	return mAge;
}

int User::getType()
{
	return mType;
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
