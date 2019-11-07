// 18120256.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ListSach.h"
#include "MangHoaDon.h"
#include "Sach.h"
#include "User.h"
#include "BookStore.h"

int main()
{
	/*ListSach Ke1;
	User defaultUser; string name = "ABC", pass = "123";
	defaultUser.setName(name); defaultUser.setPass(pass); defaultUser.setAge(18);
	name = ""; pass = "";
	Guest g;
	Ke1.fNhapListSach();
	Ke1.fXuatListSach();
	bool dk = true;
	bool dangNhap = false;
	int chon;*/
	/*while (!dangNhap)
	{
		cout << "1. Dang nhap" << endl;
		cout << "2. Tim sach" << endl;
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Ten dang nhap: ";
			cin >> name;
			cout << "Mat khau: ";
			cin >> pass;
			if()
		default:
			break;
		}
	}*/
	/*MangHoaDon hd;
	while (dk)
	{
		HoaDon tmp; tmp.taoHoaDon(Ke1); hd.themHoaDon(tmp);
		cout << "Tiep tuc?(0,1): "; cin >> dk;
	}
	hd.inMHoaDon();*/

	//while (dk)
	//{
	//	//g.timSach(Ke1);
	//	cout << "1. Mua sach" << endl;
	//	cout << "2. Cap nhat don hang" << endl;
	//	cout << "3. Tim sach" << endl;
	//	cout << "4. In danh sach hoa don" << endl;
	//	cin >> chon;
	//	switch (chon)
	//	{
	//	case 1:
	//		defaultUser.muaSach(Ke1);
	//		break;
	//	case 2:
	//		defaultUser.capNhatDonHang();
	//		break;
	//	case 3:
	//		defaultUser.timSach(Ke1);
	//		break;
	//	case 4:
	//		defaultUser.inDanhSachHoaDon();
	//		break;
	//	default:
	//		break;
	//	}
	//	cout << endl;
	//	cout << "Tiep tuc(0,1)?? "; cin >> dk;
	//}
	//cout << endl;
	BookStore store;
	store.run();
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
