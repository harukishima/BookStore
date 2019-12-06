#ifndef __GUEST_H__
#define __GUEST_H__

#include"ListSach.h"
#include"User.h"
#include<list>
#include<string>
#include<iostream>
//#include"Global.h"
using namespace std;

class Guest
{
public:
	Guest();
	virtual ~Guest();

	void timSach(ListSach&);
};





#endif // !__GUEST_H__