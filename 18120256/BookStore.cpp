#include "BookStore.h"

BookStore::BookStore()
{
	isRun = true;
	isLogged = false;
	type = 0;
	curU = NULL;
	//Load file here
	loadUserList("user.csv");
	loadBookList("book.csv");


}

void BookStore::run()
{
	while (isRun)
	{
		int cmd;
		if (!isLogged)
		{
			menu.guessMenu();
			cin >> cmd;
			guestFunction(cmd);
		}
		else
		{
			if (curU->getType() == 1)
			{
				menu.userMenu();
				cin >> cmd;
				userFunction(cmd);
			}
			else if (curU->getType() == 0)
			{
				menu.adminMenu();
				cin >> cmd;

			}
		}
	}
}

void BookStore::loadUserList(const string& path)
{
	ifstream file(path);
	if (!file.is_open())
	{
		isRun = false;
		return;
	}
	string line;
	while (getline(file, line))
	{
		User tmp;
		tmp = splitUserLine(line, ',');
		listUser.push_back(tmp);
	}
	file.close();
}

void BookStore::loadBookList(const string& path)
{
	ifstream file(path);
	if (!file.is_open())
	{
		isRun = false;
		return;
	}
	string line;
	while (getline(file, line))
	{
		Sach tmp;
		tmp = splitBookLine(line, ',');
		Ke1.fThemSach(tmp);
	}
	file.close();
}

User BookStore::splitUserLine(string line, char delim)
{
	stringstream str(line);
	User u; string tmp;
	getline(str, tmp, delim);
	u.setType(stod(tmp));
	getline(str, tmp, delim);
	u.setName(tmp);
	getline(str, tmp, delim);
	u.setPass(tmp);
	getline(str, tmp, delim);
	u.setAge(stod(tmp));

	return u;
}

Sach BookStore::splitBookLine(string line, char delim)
{
	stringstream str(line);
	Sach s; string tmp;
	getline(str, tmp, delim);
	s.fSetID(tmp);
	getline(str, tmp, delim);
	s.fSetName(tmp);
	getline(str, tmp, delim);
	s.fSetGia(stod(tmp));
	getline(str, tmp, delim);
	s.fSetNXB(tmp);
	getline(str, tmp, delim);
	s.fSetTacGia(tmp);
	return s;
}

void BookStore::guestFunction(int cmd)
{
	string tmp;
	switch (cmd)
	{
	case 1:
		dangNhap();
		break;
	case 2:
		cin.ignore();
		guest.timSach(Ke1);
		break;
	case 3:
		Ke1.fXuatListSach();
		break;
	default:
		isRun = false;
		break;
	}
}

void BookStore::userFunction(int cmd)
{
	switch (cmd)
	{
	case 1:
		curU->muaSach(Ke1);
		break;
	case 2:
		curU->capNhatDonHang();
		break;
	case 3:
		curU->timSach(Ke1);
		break;
	case 4:
		curU->inDanhSachHoaDon();
		break;
	case 5:
		isLogged = false;
		curU = NULL;
		break;
	default:
		isRun = false;
		break;
	}
}

void BookStore::dangNhap()
{
	string user, pass;
	cout << "Ten dang nhap: "; cin >> user;
	cout << "Mat khau: "; cin >> pass;
	vector<User>::iterator it;
	for (it = listUser.begin(); it != listUser.end(); it++)
	{
		if (user == it->getName())
		{
			if (pass == it->getPass())
			{
				cout << "Dang nhap thanh cong" << endl;
				isLogged = true;
				curU = &(*it);
			}
			else
			{
				cout << "Sai mat khau" << endl;
			}
			break;
		}
	}
	if(!isLogged) 
		cout << "Khong ton tai ten dang nhap" << endl;
}

