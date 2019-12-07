#ifndef __DISCOUNT_H__
#define __DISCOUNT_H__


#include<string>
#include<fstream>
#include<sstream>
using namespace std;

class Discount
{
public:
	float child = 0, teen = 0, adult = 0, elder = 0;
	Discount();
	void loadDiscountInfor(const string&);
	void exportDiscountInfor(const string&);
};




#endif // !__DISCOUNT_H__