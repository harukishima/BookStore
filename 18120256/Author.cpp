#include "Author.h"

Author::Author()
{
	mType = 3;
}

void Author::themSach(ListSach& Ke)
{
	cout << "Nhap ten sach: ";
	string tenSach; cin.ignore();
	getline(cin, tenSach);
	Sach* tmp; tmp = Ke.findBook(tenSach);
	if (tmp == NULL)
	{
		return;
	}
	if (tmp->hidAuthor && tmp->fGetTacGia() != mName)
	{
		cout << "Khong the them" << endl;
		return;
	}
	list.push_back(tmp);
	tmp->fSetTacGia(this->getName());
}

void Author::xoaSach()
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
		(*xoa)->fSetTacGia("");
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
				(*it)->fSetTacGia("");
			}
		}
	}
}

void Author::suaSach()
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

void Author::inDanhSach()
{
	vector<Sach*>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		(*it)->inSach();
	}
}

void Author::anSach(bool hid)
{
	cout << "Nhap ma so sach: ";
	string id;
	cin >> id;
	vector<Sach*>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		if ((*it)->fGetID() == id)
		{
			if (hid)
			{
				(*it)->hidPublisher = (*it)->hidUser = true;
				cout << "Khoa thanh cong" << endl;
			}
			else
			{
				(*it)->hidPublisher = (*it)->hidUser = false;
				cout << "Mo khoa thanh cong" << endl;
			}
			return;
		}
	}
	cout << "Khong tim thay ma so" << endl;
}

void Author::printInformation()
{
	cout << "Ten dang nhap: " << mUsername << endl;
	cout << "Ten: " << mName << endl;
}

ostream& operator<<(ostream& out, Author scr)
{
	out << scr.mType << "," << scr.mUsername << "," << scr.mPass << "," << scr.mName;
	return out;
}
