#include "Admin.h"

Admin::Admin()
{
	mUsername = "admin";
	mPass = "admin";
	mType = 0;
}

void Admin::printUserList(list<User>& uList)
{
	list<User>::iterator it;
	for (it = uList.begin(); it != uList.end(); it++)
	{
		it->printInformation();
		cout << endl;
	}
}

void Admin::printPublisherList(list<NXB>&pList)
{
	list<NXB>::iterator it;
	for (it = pList.begin(); it != pList.end(); it++)
	{
		it->printInformation();
		cout << endl;
	}
}

void Admin::printAuthorList(list<Author>&aList)
{
	list<Author>::iterator it;
	for (it = aList.begin(); it != aList.end(); it++)
	{
		it->printInformation();
		cout << endl;
	}
}

bool Admin::isNameExist(const string& name, list<NXB>& pList, list<Author>& aList)
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

void Admin::blacklist(ListSach& ke, list<NXB>& pList, list<Author>& aList)
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
	if (!isNameExist(name, pList, aList))
	{
		cout << "Khong tim thay ten yeu cau" << endl;
		return;
	}
	tmp->blackList.push_back(name);
	cout << "An thanh cong" << endl;
}

void Admin::discountManagement(Discount& dis)
{
	cout << "1. Tre em (0-10)" << endl;
	cout << "2. Vi thanh nien (0-17)" << endl;
	cout << "3. Nguoi lon (17-59)" << endl;
	cout << "4. Nguoi gia (60 tro len)" << endl;
	int cmd;
	cin >> cmd;
	cout << "Nhap khuyen mai (0-100): ";
	float discount;
	cin >> discount;
	if (discount < 0 || discount > 100)
	{
		cout << "Khong hop le" << endl;
		return;
	}
	discount /= 100;
	switch (cmd)
	{
	case 1:
		dis.child = discount;
		break;
	case 2:
		dis.teen = discount;
		break;
	case 3:
		dis.adult = discount;
		break;
	case 4:
		dis.elder = discount;
		break;
	default:
		break;
	}
}

void Admin::lockBook(ListSach& Ke, bool hid)
{
	cout << "Nhap ma so: ";
	string id;
	cin >> id;
	cout << "1. User" << endl;
	cout << "2. Nha xuat ban" << endl;
	cout << "3. Tac gia" << endl;
	cout << "Chon: ";
	int cmd;
	cin >> cmd;
	vector<Sach>::iterator it;
	for (it = Ke.LIST.begin(); it != Ke.LIST.end(); it++)
	{
		if (it->fGetID() == id)
		{
			switch (cmd)
			{
			case 1:
				it->hidUser = hid;
				break;
			case 2:
				it->hidPublisher = hid;
				break;
			case 3:
				it->hidAuthor = hid;
				break;
			default:
				break;
			}
			return;
		}
	}
	cout << "Khong tim thay ma so" << endl;
}

void Admin::printInformation()
{
	cout << "Ten dang nhap: " << mUsername << endl;
	cout << "Ten: " << mName << endl;
}

ostream& operator<<(ostream& out, Admin scr)
{
	out << scr.mType << "," << scr.mUsername << "," << scr.mPass << "," << scr.mName;
	return out;
}
