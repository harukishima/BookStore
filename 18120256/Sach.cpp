#include "Sach.h"



Sach::Sach()
{
	this->ID = "";
	this->TENSACH = "";
	this->GIASACH = -1;
}

Sach::Sach(string id, string tensach, int giasach)
{
	this->ID = id;
	this->TENSACH = tensach;
	this->GIASACH = giasach;
}

Sach::Sach(const Sach& a)
{
	this->ID = a.ID;
	this->TENSACH = a.TENSACH;
	this->GIASACH = a.GIASACH;
	this->NXB = a.NXB;
	this->TACGIA = a.TACGIA;
	for (int i = 0; i < a.blackList.size(); i++)
	{
		this->blackList[i] = a.blackList[i];
	}
}


Sach::~Sach()
{
	TENSACH = "";
	ID = "";
	GIASACH = 0;
}

Sach& Sach::operator=(const Sach& a)
{
	if (this != &a) {
		this->ID = a.ID;
		this->TENSACH = a.TENSACH;
		this->GIASACH = a.GIASACH;
		this->TACGIA = a.TACGIA;
		this->NXB = a.NXB;
		for (int i = 0; i < a.blackList.size(); i++)
		{
			this->blackList[i] = a.blackList[i];
		}
	}
	return *this;
}



void Sach::fSetID(string id)
{
	this->ID = id;
}

void Sach::fSetName(string tensach)
{
	this->TENSACH = tensach;
}

void Sach::fSetGia(int giasach)
{
	this->GIASACH = giasach;
}

void Sach::fSetTacGia(string tacgia)
{
	TACGIA = tacgia;
}

void Sach::fSetNXB(string nxb)
{
	NXB = nxb;
}

//void Sach::fSetTacGia(string tacgia)
//{
//	TACGIA = tacgia;
//}
//
//void Sach::fSetNXB(string nxb)
//{
//	NXB = nxb;
//}

void Sach::fNhapSach()
{
	string id, ten; int gia;
	cout << "MS: "; cin >> id;
	cin.ignore();
	cout << "Ten sach: "; getline(cin, ten);
	cout << "Gia sach: "; cin >> gia;
	fSetID(id); fSetName(ten); fSetGia(gia);
}

string Sach::fGetID()
{
	return this->ID;
}

string Sach::fGetName()
{
	return this->TENSACH;
}

string Sach::fGetTacGia()
{
	return TACGIA;
}

string Sach::fGetNXB()
{
	return NXB;
}

//string Sach::fGetTacGia()
//{
//	return TACGIA;
//}
//
//string Sach::fGetNXB()
//{
//	return NXB;
//}

int Sach::fGetGia()
{
	return this->GIASACH;
}

void Sach::inSach()
{
	cout << "ID: " << fGetID() << endl;
	cout << "Ten sach: " << fGetName() << endl;
	cout << "Gia sach: " << fGetGia() << endl;
	cout << "NXB: " << fGetNXB() << endl;
	cout << "Tac gia: " << fGetTacGia() << endl << endl;
}

bool Sach::checkBlackList(const string& name)
{
	vector<string>::iterator it;
	for (it = blackList.begin(); it != blackList.end(); it++)
	{
		if (name == *it)
		{
			return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& out, Sach s)
{
	out << s.fGetID() << "," << s.fGetName() << "," << s.fGetGia() << "," << s.fGetNXB() << "," << s.fGetTacGia();
	vector<string>::iterator it;
	for (it = s.blackList.begin(); it != s.blackList.end(); it++)
	{
		out << "," << *it;
	}
	return out;
}
