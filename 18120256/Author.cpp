#include "Author.h"

Author::Author()
{
	mType = 3;
}

void Author::printInformation()
{
	cout << "Ten dang nhap: " << mUsername << endl;
	cout << "Ten: " << mName << endl;
}

ostream& operator<<(ostream& out, Author scr)
{
	out << scr.mType << "," << scr.mUsername << "," << scr.mPass << "," << scr.mName;
	return out;
}
