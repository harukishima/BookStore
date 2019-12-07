#include "Discount.h"

Discount::Discount()
{
}

void Discount::loadDiscountInfor(const string& path)
{
	ifstream file(path);
	if (!file.is_open()) return;
	string tmp;
	while (getline(file, tmp))
	{
		stringstream str(tmp);
		string dis;
		getline(str, dis, ',');
		child = stof(dis);
		getline(str, dis, ',');
		teen = stof(dis);
		getline(str, dis, ',');
		adult = stof(dis);
		getline(str, dis, ',');
		elder = stof(dis);
	}
	file.close();
}

void Discount::exportDiscountInfor(const string& path)
{
	ofstream file(path);
	if (!file.is_open()) return;
	file << child << "," << teen << "," << adult << "," << elder;
	file.close();
}
