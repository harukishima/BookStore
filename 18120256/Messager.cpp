#include "Messager.h"

void Messager::sendMessage(const string& sender,const string& receiver, const string& message)
{	
	string path = "Message\\" + receiver + ".txt";
	ofstream file; 
	file.open(path, ios::app);
	if (!file.is_open())
	{
		return;
	}
	Date current; current.Now();
	file << current << "\t" << sender << ": " << message << endl;
	file.close();
}

void Messager::inbox(const string& owner)
{
	string path = "Message\\" + owner + ".txt";
	ifstream file(path);
	if (!file.is_open())
	{
		return;
	}
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}
	file.close();
}
