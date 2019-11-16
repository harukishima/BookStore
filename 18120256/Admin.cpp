#include "Admin.h"

Admin::Admin()
{
	mUsername = "admin";
	mPass = "admin";
	mType = 0;
}

void Admin::printUserList()
{
	list<User>::iterator it;
	for (it = uList.begin(); it != uList.end(); it++)
	{
		it->printInformation();
		cout << endl;
	}
}

void Admin::printPublisherList()
{
	list<NXB>::iterator it;
	for (it = pList.begin(); it != pList.end(); it++)
	{
		it->printInformation();
		cout << endl;
	}
}

void Admin::printAuthorList()
{
	list<Author>::iterator it;
	for (it = aList.begin(); it != aList.end(); it++)
	{
		it->printInformation();
		cout << endl;
	}
}

bool Admin::isNameExist(const string& name)
{
	bool dk = false;
	list<NXB>::iterator itP;
	for (itP = pList.begin(); itP != pList.end(); itP++)
	{
		if (name == itP->getUsername())
		{
			dk = true;
		}
	}
	list<Author>::iterator itA;
	for (itA = aList.begin(); itA != aList.end(); itA++)
	{
		if (name == itA->getUsername())
		{
			dk = true;
		}
	}
	return dk;
}

void Admin::blacklist(ListSach& ke)
{
	ke.fXuatListSach();
	string id, name;
	cout << "Nhap ma sach can an: ";
	cin >> id;
	Sach* tmp = NULL;
	tmp = ke.findBookBaseOnID(id);
	if (tmp == NULL)
	{
		cout << "Khong tim thay sach" << endl;
		return;
	}
	cout << "Nhap ten dang nhap can an: ";
	cin >> name;
	if (!isNameExist(name))
	{
		cout << "Khong tim thay ten yeu cau" << endl;
		return;
	}
	tmp->blackList.push_back(name);
	cout << "An thanh cong" << endl;
}

void Admin::printInformation()
{
	cout << "Ten dang nhap: " << mUsername << endl;
	cout << "Ten: " << mName << endl;
}
