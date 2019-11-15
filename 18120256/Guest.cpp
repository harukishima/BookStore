#include "Guest.h"



Guest::Guest()
{
}


Guest::~Guest()
{
}

void Guest::timSach(ListSach& ke)
{
	cin.ignore();
	cout << "Nhap ten sach: ";
	string tensach;
	getline(cin, tensach);
	Sach *tmp = ke.findBook(tensach);
	if (tmp == NULL)
	{
		cout << "Khong tim thay" << endl;
		return;
	}
	if (tmp->fGetID() == "") {
		cout << "Khong tim thay" << endl;
	}
	else
	{
		cout << *tmp;
	}
}
