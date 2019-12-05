#include "BookStore.h"

BookStore::BookStore()
{
	isRun = true;
	isLogged = false;
	type = 0;
	//Load file here
	loadAdminList("admin.csv");
	loadUserList("user.csv");
	loadBookList("book.csv");
	loadPublisherList("nxb.csv");
	loadAuthorList("author.csv");
	loadBookToPointerList();
	list<User>::iterator it;
	for (it = uList.begin(); it != uList.end(); it++)
	{
		it->loadBill(Ke1);
	}
}

BookStore::~BookStore()
{
	exportAdminList("admin.csv");
	exportUserList("user.csv");
	exportPublisherList("nxb.csv");
	exportAuthorList("author.csv");
	Ke1.fXuatFileSach("book.csv");
	list<User>::iterator it;
	for (it = uList.begin(); it != uList.end(); it++)
	{
		it->exportBill();
	}
}

void BookStore::run()
{
	while (isRun)
	{
		int cmd;
		if (!isLogged)
		{
			menu.guestMenu();
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
			if (curAd)
			{
				menu.adminMenu();
				cin >> cmd;
				adminFunction(cmd);
			}
			if (curP)
			{
				menu.publisherMenu();
				cin >> cmd;
				publisherFunction(cmd);
			}
			if (curA)
			{
				menu.publisherMenu();
				cin >> cmd;
				authorFunction(cmd);
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
			uList.push_back(tmp);
		}
	}
	file.close();
}

void BookStore::loadAdminList(const string& path)
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
		Admin tmp;
		tmp = splitAdminLine(line, ',');
		if (tmp.getType() != -1)
		{
			adList.push_back(tmp);
		}
	}
	file.close();
}

void BookStore::exportAdminList(const string& path)
{
	ofstream file(path);
	if (!file.is_open())
	{
		isRun = false;
		return;
	}
	list<Admin>::iterator it;
	for (it = adList.begin(); it != adList.end(); it++)
	{
		file << (*it) << endl;
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
	for (it = uList.begin(); it != uList.end(); it++)
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
			pList.push_back(tmp);
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
	for (it = pList.begin(); it != pList.end(); it++)
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
			for (itP = pList.begin(); itP != pList.end(); itP++)
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
			for (itA = aList.begin(); itA != aList.end(); itA++)
			{
				if (itA->getName() == it->fGetTacGia())
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
			aList.push_back(tmp);
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
	for (it = aList.begin(); it != aList.end(); it++)
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

Admin BookStore::splitAdminLine(string line, char delim)
{
	stringstream str(line);
	string tmp;
	getline(str, tmp, delim);
	Admin a;
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

void BookStore::loadPublisherAndAuthor()
{
	vector<Sach>::iterator it;
	for (it = Ke1.LIST.begin(); it != Ke1.LIST.end(); it++)
	{
		if (it->fGetNXB() != "")
		{
			list<NXB>::iterator itP;
			for (itP = pList.begin(); itP != pList.end(); itP++)
			{
				if (it->fGetNXB() == itP->getName())
				{
					itP->list.push_back(&(*it));
				}
			}
		}
		if (it->fGetTacGia() != "")
		{
			list<Author>::iterator itA;
			for (itA = aList.begin(); itA != aList.end(); itA++)
			{
				if (it->fGetTacGia() == itA->getName())
				{
					itA->list.push_back(&(*it));
				}
			}
		}
	}
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
	case 4:
		dangKi();
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
		guest.timSach(Ke1);
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

void BookStore::adminFunction(int cmd)
{
	int tmp; string a;
	switch (cmd)
	{
	case 1:

		break;
	case 2:
		Ke1.fXuatListSach();
		break;
	case 3:
		Ke1.fXuatListSach();
		cout << "Nhap STT sach: ";
		cin >> tmp;
		Ke1.fXoaSach(tmp);
		break;
	case 4:
		cin.ignore();
		getline(cin, a);
		Ke1.fTimSach(a);
		break;
	case 5:
		Ke1.themSach();
		break;
	case 6:
		Ke1.fXoaTatCa();
		break;
	case 7:
		dangXuat();
		break;
	case 8:
		curAd->blacklist(Ke1, pList, aList);
		break;
	default:
		isRun = false;
		break;
	}
}

void BookStore::publisherFunction(int cmd)
{
	switch (cmd)
	{
	case 1:
		curP->inDanhSach();
		break;
	case 2:
		curP->themSach(Ke1);
		break;
	case 3:
		curP->xoaSach();
		break;
	case 4:
		curP->suaSach();
		break;
	case 5:
		dangXuat();
		break;
	default:
		isRun = false;
		break;
	}
}

void BookStore::authorFunction(int cmd)
{
	switch (cmd)
	{
	case 1:
		curA->inDanhSach();
		break;
	case 2:
		curA->themSach(Ke1);
		break;
	case 3:
		curA->xoaSach();
		break;
	case 4:
		curA->suaSach();
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
	list<Admin>::iterator itAd;
	for (itAd = adList.begin(); itAd != adList.end(); itAd++)
	{
		if (user == itAd->getUsername())
		{
			if (pass == itAd->getPass())
			{
				cout << "Dang nhap thanh cong" << endl;
				isLogged = true;
				curAd = &(*itAd);
			}
			else
			{
				cout << "Sai mat khau" << endl;
			}
			break;
		}
	}
	list<User>::iterator itU;
	for (itU = uList.begin(); itU != uList.end(); itU++)
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
	for (itP = pList.begin(); itP != pList.end(); itP++)
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
	for (itA = aList.begin(); itA != aList.end(); itA++)
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

void BookStore::dangKi()
{
	string user, pass;
	cout << "Nhap ten dang nhap: ";
	cin >> user;
	list<User>::iterator it;
	for (it = uList.begin(); it != uList.end(); it++)
	{
		if (it->getName() == user)
		{
			cout << "Da ton tai ten dang nhap\n";
			return;
		}
	}
	cout << "Nhap mat khau: ";
	cin >> pass;
	int age;
	cout << "Nhap tuoi: ";
	cin >> age;
	cin.ignore();
	cout << "Nhap ho ten: ";
	string name;
	getline(cin, name);
	User newU(user, pass, name, age);
	uList.push_back(newU);
}


void BookStore::dangXuat()
{
	curU = NULL;
	curP = NULL;
	curA = NULL;
	curAd = NULL;
	isLogged = false;
}

