#ifndef phone_h
#define phone_h
#include <string>
using namespace std;
class phone
{
private:
	string number;
	string type;
public:
	void print();
	void setphones(string);
	void settype(string);
	bool research(string item);
	string getnum();
	string  gettype();
	phone(string num, string typ);
	phone();
};
#endif