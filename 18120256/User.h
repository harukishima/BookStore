#ifndef __USER_H__
#define __USER_H__


#include "Guest.h"
#include "MangHoaDon.h"
#include "HoaDon.h"
#include "Account.h"

class User :
	public Account
{
private:
	int mAge;
	MangHoaDon mHoadon;
public:
	User();
	User(string, string, string, int);
	virtual ~User();

	
	void setAge(const int&);

	int getAge();
	friend ostream& operator<<(ostream& out, User scr);

	void muaSach(ListSach&);
	void capNhatDonHang();
	void inDanhSachHoaDon();
	void loadBill(ListSach& Ke);
	void exportBill();

	virtual void printInformation();
};





#endif // !__USER_H__