#ifndef __MESSAGER_H__
#define __MESSAGER_H__

#include<string>
#include<fstream>
#include<iostream>
#include"Date.h"
using namespace std;

class Messager
{
public:
	static void sendMessage(const string& sender, const string& receiver, const string& message);
	static void inbox(const string& owner);
};













#endif // !__MESSAGER_H__