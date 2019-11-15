#ifndef __NXB_H__
#define __NXB_H__

#include"ListSach.h"
#include"User.h"
#include"Account.h"

class NXB : public Account
{
public:
	vector<Sach*> list;
	NXB();
	virtual ~NXB();
	void themSach(ListSach&);
	void xoaSach();
};






#endif // !__NXB_H__



