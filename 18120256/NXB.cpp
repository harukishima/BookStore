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
