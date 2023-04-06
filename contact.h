#ifndef contact_h
#define contact_h
#include "phone.h"
#include <string>
using namespace std;
class contact:public phone
{
private:
	int id;
	int gender;
	int count;
	int size;
	int count_contact;
	string first_name;
	string city;
	phone* client;
public:
	contact();
	void input();
	void print()const;
	void setname(string name);
	void setphone(string, string);
	void numberofphones(int);
	void setcity(string);
	bool research_city(string item);
	bool research_phone(string item);
	void setid(int);
	int getid(int);
	bool research_name(string item);
	string getname();
	~contact();
};
#endif