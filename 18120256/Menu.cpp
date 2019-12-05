#include "Menu.h"

Menu::Menu()
{
}

void Menu::guestMenu()
{
	cout << "1. Dang nhap" << endl;
	cout << "2. Tim sach" << endl;
	cout << "3. Hien thi tat ca sach" << endl;
	cout << "4. Dang ki" << endl;
	cout << "0. Exit" << endl;
}

void Menu::userMenu()
{
	cout << "1. Mua sach" << endl;
	cout << "2. Cap nhat don hang" << endl;
	cout << "3. Tim sach" << endl;
	cout << "4. In danh sach hoa don" << endl;
	cout << "5. Dang xuat" << endl;
	cout << "0. Thoat" << endl;
}

void Menu::adminMenu()
{
	cout << "1. Nhap list sach" << endl;
	cout << "2. Xuat list sach" << endl;
	cout << "3. Xoa sach" << endl;
	cout << "4. Tim sach" << endl;
	cout << "5. Them sach" << endl;
	cout << "6. Xoa tat ca sach" << endl;
	cout << "7. Dang xuat" << endl;
	cout << "8. Blacklist" << endl;
	cout << "0. Thoat" << endl;
}

void Menu::publisherMenu()
{
	cout << "1. Xem sach" << endl;
	cout << "2. Them sach" << endl;
	cout << "3. Xoa sach" << endl;
	cout << "4. Sua gia" << endl;
	cout << "5. Dang xuat" << endl;
	cout << "0. Thoat" << endl;
}
