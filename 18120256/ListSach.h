#ifndef __LISTSACH_H__
#define __LISTSACH_H__
#include "Sach.h"
#include <fstream>
#include <vector>
class ListSach
{
	
public:
	vector<Sach>LIST;
	ListSach();
	~ListSach();
	void fNhapListSach();
	void fXuatListSach();
	void fXuatFileSach(const string&);
	void fTimSach(string);
	void fTim1Sach(int it);
	Sach* findBook(string);
	Sach* findBookBaseOnID(string);
	void fXoaSach(int i);
	void fXoaTatCa();
	void fThemSach(Sach);
};

#endif // !__LISTSACH_H__