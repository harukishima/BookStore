#include "ListSach.h"



ListSach::ListSach()
{
}


ListSach::~ListSach()
{
	if (!this->LIST.empty())
		this->LIST.clear();
}

void ListSach::fNhapListSach()
{
	int size;
	cout << "Nhap so luong sach: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		Sach tmp;
		cout << i + 1 << endl;
		tmp.fNhapSach();
		LIST.push_back(tmp);
	}

}

void ListSach::fXuatListSach()
{
	if (!LIST.empty())
	{
		cout << "-----XUAT LIST SACH-----" << endl;
		for (int i = 0; i < LIST.size(); i++)
		{
			cout << i + 1 << endl;
			cout << "ID: " << LIST[i].fGetID() << endl;
			cout << "Ten sach: " << LIST[i].fGetName() << endl;
			cout << "Gia sach: " << LIST[i].fGetGia() << endl;
			cout << "NXB: " << LIST[i].fGetNXB() << endl;
			cout << "Tac gia: " << LIST[i].fGetTacGia() << endl << endl;
		}
	}
}

void ListSach::fXuatFileSach(const string& path)
{
	ofstream file(path);
	if (!file.is_open())
	{
		cout << "Khong xuat duoc file sach" << endl;
		return;
	}
	vector<Sach>::iterator it;
	for (it = LIST.begin(); it != LIST.end(); it++)
	{
		file << (*it) << endl;
	}
	file.close();
}

void ListSach::fTimSach(string tensach)
{
	int count = 0; int it;
	for (int i = 0; i < LIST.size(); i++)
	{
		if (tensach == LIST[i].fGetName())
		{
			count++;
			it = i;
		}
	}
	if (count == 0)
		cout << "Khong tim thay sach" << endl;
	else if (count == 1)
	{
		cout << "Tim thay 1 cuon sach" << endl;
		fTim1Sach(it);
	}
	else
	{
		cout << "Tim thay " << count << " cuon sach" << endl;
		cout << "Nhap ma sach: ";
		string ms;
		cin >> ms;
		count = 0;
		for (int i = 0; i < LIST.size(); i++)
		{
			if(tensach == LIST[i].fGetName() || ms == LIST[i].fGetID())
			{
				count++;
				it = i;
			}
		}
		if (count == 0) cout << "Khong tim thay sach" << endl;
		else
		{
			fTim1Sach(it);
		}
	}

}

void ListSach::fTim1Sach(int it)
{
	int tmp;
	cout << "1. Xoa sach" << endl;
	cout << "2. Cap nhat gia" << endl;
	cin >> tmp;
	switch (tmp)
	{
	case 1:
		fXoaSach(it);
		break;
	case 2:
		cout << "Nhap gia moi: ";
		cin >> tmp;
		LIST[it].fSetGia(tmp);
		break;
	default:
		break;
	}
}

Sach* ListSach::findBook(string ten)
{
	vector<Sach>::iterator it;
	int count = 0;
	Sach *tmp = NULL;
	for (it = LIST.begin(); it != LIST.end(); ++it)
	{
		if (it->fGetName() == ten)
		{
			count++;
			tmp = &(*it);
		}
	}
	if (count > 1)
	{
		count = 0;
		cout << "Tim thay nhieu cuon sach" << endl;
		cout << "MS: ";
		string ms;
		cin >> ms;
		for (it = LIST.begin(); it != LIST.end(); ++it)
		{
			if (it->fGetID() == ms)
			{
				count++;
				tmp = &(*it);
			}
		}
	}
	return tmp;
}

Sach* ListSach::findBookBaseOnID(string id)
{
	vector<Sach>::iterator it;
	Sach* tmp = NULL;
	for (it = LIST.begin(); it != LIST.end(); ++it)
	{
		if (it->fGetID() == id)
		{
			tmp = &(*it);
		}
	}
	return tmp;
}

void ListSach::fXoaSach(int i)
{
	if (!LIST.empty())
	{
		this->LIST.erase(LIST.begin()+i-1);
	}
}

void ListSach::fXoaTatCa()
{
	LIST.clear();
}

void ListSach::fThemSach(Sach s)
{
	LIST.push_back(s);
}

void ListSach::themSach()
{
	string ms, ten; int gia;
	cout << "Nhap MS: ";
	cin >> ms;
	cin.ignore();
	cout << "Nhap ten sach: ";
	getline(cin, ten);
	cout << "Nhap so luong: ";
	cin >> gia;
	Sach tmp;
	tmp.fSetID(ms);
	tmp.fSetName(ten);
	tmp.fSetGia(gia);
	fThemSach(tmp);
}
