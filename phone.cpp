#include "phone.h"
#include <iostream>
using namespace std;
phone::phone() {}
phone::phone(string num, string my_type)
{
	number = num;
	type = my_type;
}
void phone::setphones(string phones)
{
	number = phones;
}
void phone::settype(string types)
{
	type = types;
}
void phone::print()
{
	cout << "Number : " << number << " | | " << type << endl;
}
bool phone::research(string item)
{
	if (number == item)
		return true;
	else
		return false;
}
string phone::getnum()
{
	return number;
}
string phone::gettype()
{
	return type;
}