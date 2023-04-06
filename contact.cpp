#include "contact.h"
#include "phone.h"
#include <string>
#include <iostream>
using namespace std;
contact::contact()
{
	size  = 100;
	count = 0;
	count_contact = 0;
	id = 0;
	client = new phone[size];
}
void contact::input()
{
	//*************INPUT*******************	
	count_contact++;
	cout << "Enter your name : ";
	cin.get();
	getline(cin, first_name);
	cout << "Enter your gender [Male]=0,[Female]=1 : ";
	cin >> gender;
	cout << "How many numbers : ";
	int num;
	cin >> num;
	/*/if (num == 0 && count > 0)
	 {
		count = 0;//
	 }
    else {*/
	count = 0;
		for (int i = 0; i < num; i++)
		{
			
			cout << "Enter number " << i + 1 << "-" << num << ": ";
			string defname, deftype;
			cin >> defname;
			cout << "Enter it's Type :";
			cin >> deftype;
			phone* new_client = new phone(defname, deftype);
			client[count] = *new_client;
			count++;
			delete new_client;
		}
	    // }
	cout << "Enter your city : ";
	cin.get();
	getline(cin, city);
}
void contact::print()const
{
	//**************PRINT********************
	if (count_contact > 0)
	{
		/*cout << "Name : " << first_name << endl
			<< "Gender : " << (gender == 0 ? "Male" : "Female") << endl
			<< "City : " << city << endl
			<< "ID : "<<id<<endl;*/
		cout<<"ID : "<<id<<"           "
			<<"Name : " << first_name << "           "
		    <<"Gender : "<< (gender == 0 ? "Male" : "Female")
			<<"           "<<"city : "<<city<<"\n";
		if (count > 0)
		{
			cout << "    Phone List : \n";
			for (int i = 0; i < count; i++)
			{
				cout << i + 1 << " - ";
				client[i].print();
			}
		}
		else cout << "No Phones Registerd\n";
	}
	else
		cout << "No Contacts to print \n";

}
int contact::getid(int m_id)
{
	id = m_id;
	return id;
}
void contact::setid(int m_id)
{
	id=m_id;
}
void contact::setcity(string ccity)
{
	city = ccity;
}
void contact::numberofphones(int n)
{
	count = n;
}
void contact::setphone(string pphone ,string ttype)
{
	    count = 0;
		phone* editphone = new phone(pphone, ttype);
		client[count++] = *editphone;
	    //count++;
		delete editphone;
}
void contact::setname(string name)
{
	first_name = name;
}
string contact::getname()
{
	return first_name;
}
/*string contact::getphone(int i)
{
	//return client[]
}*/
bool contact::research_name(string item)
{
	if (count_contact > 0)
	{
			if (first_name == item)
				return true;
			else
				return false;
	}
	else
		return false;
}
bool contact::research_city(string My_city)
{
	if (count_contact > 0)
	{
		if (city == My_city)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
bool contact::research_phone(string sign)
{
	if (count_contact > 0&&count>0)
	{
		for (int i = 0; i < count; i++)
		{
			if (client[i].research(sign))
			{
				return true;
			}
			else 
			return false;
		}
	}
	return false;
}
contact ::~contact()
{
	delete []client;
}