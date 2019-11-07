#ifndef __USER_H__
#define __USER_H__


#include "Guest.h"
#include "MangHoaDon.h"
#include "HoaDon.h"

class User :
	public Guest
{
private:
	string mName;
	string mPass;
	int mAge;
	MangHoaDon mHoadon;
	int mType = 1;
public:
	User();
	virtual ~User();

	void setName(string&);
	void setPass(string&);
	void setAge(const int&);
	void setType(const int&);
	string getName();
	string getPass();
	int getAge();
	int getType();

	void muaSach(ListSach&);
	void capNhatDonHang();
	void inDanhSachHoaDon();
};





#endif // !__USER_H__


