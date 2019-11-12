#ifndef __USER_H__
#define __USER_H__


#include "Guest.h"
#include "MangHoaDon.h"
#include "HoaDon.h"
#include "Account.h"

class User :
	public Account, public Guest
{
private:
	int mAge;
	MangHoaDon mHoadon;
public:
	User();
	virtual ~User();

	
	void setAge(const int&);

	int getAge();
	

	void muaSach(ListSach&);
	void capNhatDonHang();
	void inDanhSachHoaDon();
};





#endif // !__USER_H__



