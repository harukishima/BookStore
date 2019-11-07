#ifndef __GUEST_H__
#define __GUEST_H__

#include"ListSach.h"
#include<string>
#include<iostream>
using namespace std;

class Guest
{
public:
	Guest();
	virtual ~Guest();

	void timSach(ListSach&);
};





#endif // !__GUEST_H__