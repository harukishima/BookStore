#include "NXB.h"



NXB::NXB()
{
	mType = 2;
}


NXB::~NXB()
{
}

void NXB::themSach(ListSach& Ke)
{
	cout << "Nhap ten sach: ";
	string tenSach; cin.ignore();
	getline(cin, tenSach);
	Sach* tmp; tmp = Ke.findBook(tenSach);
	if (tmp == NULL)
	{
		return;
	}
	list.push_back(tmp);
	tmp->fSetNXB(this->getName());
}

void NXB::xoaSach()
{
	cout << "Nhap ten sach: ";
	string tenSach; cin.ignore();
	getline(cin, tenSach);
	vector<Sach*>::iterator it; vector<Sach*>::iterator xoa;
	int count = 0;
	Sach* tmp;
	for (it = list.begin(); it != list.end(); ++it)
	{
		if ((*it)->fGetName() == tenSach)
		{
			count++;
			tmp = *it;
			xoa = it;
		}
	}
	if (count == 1)
	{
		list.erase(xoa);
		(*xoa)->fSetNXB("");
	}
	if (count > 1)
	{
		string id;
		cout << "Nhap ms: "; cin >> id;
		for (it = list.begin(); it != list.end(); ++it)
		{
			if ((*it)->fGetID() == id)
			{
				list.erase(it);
				(*it)->fSetNXB("");
			}
		}
	}
}

void NXB::suaSach()
{
	cout << "Nhap ma sach can sua: ";
	string id;
	cin >> id;
	vector<Sach*>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		if (id == (*it)->fGetID())
		{
			if ((*it)->checkBlackList(mName))
			{
				cout << "Ban khong the sua duoc sach nay" << endl;
				return;
			}
			cout << "Nhap gia moi: ";
			int gia;
			cin >> gia;
			(*it)->fSetGia(gia);
			return;
		}
	}
}

void NXB::printInformation()
{
	cout << "Ten dang nhap: " << mUsername << endl;
	cout << "Ten: " << mName << endl;
}

ostream& operator<<(ostream& out, NXB scr)
{
	out << scr.mType << "," << scr.mUsername << "," << scr.mPass << "," << scr.mName;
	return out;
}
