#include "contactbook.h"
#include <iostream>
#include <string>
#include <algorithm>
contactbook::contactbook(int m_size)
{
	contact_count = 0;
	//deleted_counter = 0;
	contact_size = m_size;
	my_contacts = new contact[contact_size];
}
void contactbook::add()
{
		my_contacts[contact_count++].input();
		cout << "\nNote:-\n";
		cout << "-->> ";
		cout << "(Your ID is : " << my_contacts[contact_count - 1].getid(contact_count) << ")\n";
	
}
void contactbook::Edit()
{
	if (contact_count > 0)
	{
		int u_id;
		int flag = 0;
		cout << "Enter user ID : ";
		cin >> u_id;
		if (u_id > contact_count)
		   cout << "NO TO EDIT \"Enter right ID. \"";
		else
		{
			int choice=-1;
			do {
				cout << "Select Edit type: \n"
					<< "[1]- Name.\n"
					<< "[2]- City.\n"
					<< "[3]- Phone\n"
					<< "Enter your choice : ";
				cin >> choice;
				cout << endl;
				if (choice == 1)
				{
					string nname;
					cin.get();
					cout << "Enter the name : ";
					getline(cin, nname);
					my_contacts[u_id - 1].setname(nname);
				}
				if (choice == 2)
				{
					cout << "Enter The City : ";
					string ccity;
					cin >> ccity;
					cout << endl;
					my_contacts[u_id - 1].setcity(ccity);
				}
				if (choice == 3)
				{
					cout << "How many Phone numbers do you have : ";
					int n;
					cin >> n;
					if (n == 0)
					{
						my_contacts[u_id - 1].numberofphones(n);
					}
					else {
						string phonee, typee;
						for (int i = 0; i < n; i++)
						{
							cout << "Enter The Phone [1-" << n << "] : ";
							cin >> phonee;
							cout << "Enter it's Type : ";
							cin >> typee;
							my_contacts[u_id - 1].setphone(phonee, typee);
						}
					}
				}
			} while (choice==0);
			//my_contacts[u_id-1].input();
			flag = 1;
		}
		if (flag)
		{
			cout << "~Edited\n";
		}
		else
			cout << "~Not Edited\n";
	}
	else
		cout << "No Users to Edit\n";
}
void contactbook::Delete()
{
if (contact_count>0)
{
	int u_id;
	int flag = 0;
	cout << "Enter user ID : ";
	cin >> u_id;
	if (u_id > contact_count||u_id==0)
		cout << "NO TO DElete \"Enter right ID. \"\n";
	else
	{
		int ID=my_contacts[u_id - 1].getid(u_id );
		my_contacts[contact_count - 1].setid(ID);
		my_contacts[u_id - 1] = my_contacts[contact_count - 1];
		my_contacts[contact_count - 1].numberofphones(0);
		contact_count--;
		//deleted_counter=u_id;
		flag = 1;
	}
	if (flag)
		cout << "~Deleted\n";
	else
		cout << "~Not Deleted\n";
} 
}
void contactbook::show()
{
	if (contact_count > 0)
	{
		string *names;
		names = new string[contact_count];
		for (int i = 0; i < contact_count; i++)
		{
			names[i] = my_contacts[i].getname();
		}
		sort(names, names + contact_count);
		//************************************
		for (int i = 0; i < contact_count; i++)
		{
			for (int j = 0; j < contact_count; j++)
		    {
				if (my_contacts[j].research_name(names[i]))
				{
					my_contacts[j].print();
					break;
				}
		    }
			cout << "-----------------------------------------------------------------------------------\n"
				 << "-----------------------------------------------------------------------------------\n";
		} 
		delete[]names;
	}
	else
		cout << "No Users to Display\n";
}
bool contactbook:: research_names(string sign )
{
	int flag = 0;
	if (contact_count == 0)
	{
		cout << "NO Contacts to Search\n";
		return false;
	}
	else
	{
		for (int i=0;i<contact_count;i++)
		{
			if (my_contacts[i].research_name(sign))
			{
				system("cls");
				my_contacts[i].print();
				return true;
				flag = 1;
				//num = i;
				break;
			}
		}
		if (!flag)
		return false;
	}
}
bool contactbook::research_city(string city)
{
	if (contact_count == 0)
		return false;
	else
	{
		int flag = 0;
		for (int i = 0; i < contact_count; i++)
		{
			if (my_contacts[i].research_city(city))
			{
				system("cls");
				my_contacts[i].print();
				return true;
				flag = 1;
					break;
			}
		}
		if (!flag)
			return false;
	}
}
bool contactbook::research_phone(string number)
{
	int flag = 0;
	for (int i = 0; i < contact_count; i++)
	{
	   flag = 0;
		if (my_contacts[i].research_phone(number))
		{
			system("cls");
			my_contacts[i].print();
			return true;
			flag = 1;
			break;
		}
	}
	if (!flag)
		return false;
}
contactbook::~contactbook()
{
	delete[]my_contacts;
}