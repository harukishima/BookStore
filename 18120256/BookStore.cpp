#include "BookStore.h"

BookStore::BookStore()
{
	isRun = true;
	isLogged = false;
	type = 0;
	//Load file here
	loadUserList("user.csv");
	loadBookList("book.csv");
	loadPublisherList("nxb.csv");
	loadAuthorList("author.csv");
	loadBookToPointerList();
}

BookStore::~BookStore()
{
	exportUserList("user.csv");
	exportPublisherList("nxb.csv");
	exportAuthorList("author.csv");
	Ke1.fXuatFileSach("book.csv");
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
			if (curU)
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
			if (curP)
			{
				//Publisher function here
			}
			if (curA)
			{
				//Author function here
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
		if (tmp.getType() != -1)
		{
			QTV.uList.push_back(tmp);
		}
	}
	file.close();
}

void BookStore::exportUserList(const string& path)
{
	ofstream file(path);
	if (!file.is_open())
	{
		isRun = false;
		return;
	}
	list<User>::iterator it;
	for (it = QTV.uList.begin(); it != QTV.uList.end(); it++)
	{
		file << (*it) << endl;
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


void BookStore::loadPublisherList(const string& path)
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
		NXB tmp;
		tmp = splitPublisherLine(line, ',');
		if (tmp.getType() != -1)
		{
			QTV.pList.push_back(tmp);
		}
	}
	file.close();
}

void BookStore::exportPublisherList(const string& path)
{
	ofstream file(path);
	if (!file.is_open())
	{
		isRun = false;
		return;
	}
	list<NXB>::iterator it;
	for (it = QTV.pList.begin(); it != QTV.pList.end(); it++)
	{
		file << (*it) << endl;
	}
	file.close();
}

void BookStore::loadBookToPointerList()
{
	vector<Sach>::iterator it;
	for (it = Ke1.LIST.begin(); it != Ke1.LIST.end(); it++)
	{
		if (it->fGetNXB() != "")
		{
			list<NXB>::iterator itP;
			for (itP = QTV.pList.begin(); itP != QTV.pList.end(); itP++)
			{
				if (itP->getName() == it->fGetNXB())
				{
					itP->list.push_back(&(*it));
				}
			}
		}
		if (it->fGetTacGia() != "")
		{
			list<Author>::iterator itA;
			for (itA = QTV.aList.begin(); itA != QTV.aList.end(); itA++)
			{
				if (itA->getName() == it->fGetNXB())
				{
					itA->list.push_back(&(*it));
				}
			}
		}
	}
}

void BookStore::loadAuthorList(const string& path)
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
		Author tmp;
		tmp = splitAuthorLine(line, ',');
		if (tmp.getType() != -1)
		{
			QTV.aList.push_back(tmp);
		}
	}
	file.close();
}

void BookStore::exportAuthorList(const string& path)
{
	ofstream file(path);
	if (!file.is_open())
	{
		isRun = false;
		return;
	}
	list<Author>::iterator it;
	for (it = QTV.aList.begin(); it != QTV.aList.end(); it++)
	{
		file << (*it) << endl;
	}
	file.close();
}

User BookStore::splitUserLine(string line, char delim)
{
	stringstream str(line);
	string tmp;
	getline(str, tmp, delim);
	User u;
	u.setType(stod(tmp));
	getline(str, tmp, delim);
	u.setUsername(tmp);
	getline(str, tmp, delim);
	u.setPass(tmp);
	getline(str, tmp, delim);
	u.setName(tmp);
	getline(str, tmp, delim);
	u.setAge(stod(tmp));
	return u;
}

NXB BookStore::splitPublisherLine(string line, char delim)
{
	stringstream str(line);
	string tmp;
	getline(str, tmp, delim);
	NXB p;
	p.setType(stod(tmp));
	getline(str, tmp, delim);
	p.setUsername(tmp);
	getline(str, tmp, delim);
	p.setPass(tmp);
	getline(str, tmp, delim);
	p.setName(tmp);
	return p;
}

Author BookStore::splitAuthorLine(string line, char delim)
{
	stringstream str(line);
	string tmp;
	getline(str, tmp, delim);
	Author a;
	a.setType(stod(tmp));
	getline(str, tmp, delim);
	a.setUsername(tmp);
	getline(str, tmp, delim);
	a.setPass(tmp);
	getline(str, tmp, delim);
	a.setName(tmp);
	return a;
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
	while (getline(str, tmp, delim))
	{
		s.blackList.push_back(tmp);
	}
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
		dangXuat();
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
	list<User>::iterator itU;
	for (itU = QTV.uList.begin(); itU != QTV.uList.end(); itU++)
	{
		if (user == itU->getUsername())
		{
			if (pass == itU->getPass())
			{
				cout << "Dang nhap thanh cong" << endl;
				isLogged = true;
				curU = &(*itU);
			}
			else
			{
				cout << "Sai mat khau" << endl;
			}
			break;
		}
	}
	list<NXB>::iterator itP;
	for (itP = QTV.pList.begin(); itP != QTV.pList.end(); itP++)
	{
		if (user == itP->getUsername())
		{
			if (pass == itP->getPass())
			{
				cout << "Dang nhap thanh cong" << endl;
				isLogged = true;
				curP = &(*itP);
			}
			else
			{
				cout << "Sai mat khau" << endl;
			}
			break;
		}
	}
	list<Author>::iterator itA;
	for (itA = QTV.aList.begin(); itA != QTV.aList.end(); itA++)
	{
		if (user == itA->getUsername())
		{
			if (pass == itA->getPass())
			{
				cout << "Dang nhap thanh cong" << endl;
				isLogged = true;
				curA = &(*itA);
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

void BookStore::dangXuat()
{
	curU = NULL;
	curP = NULL;
	curA = NULL;
	isLogged = false;
}

