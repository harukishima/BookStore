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

ostream& operator<<(ostream& out, Sach s)
{
	out << s.fGetID() << "\t" << s.fGetName() << "\t" << s.fGetGia() << endl;
	return out;
}