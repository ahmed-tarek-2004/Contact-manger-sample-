#include <iostream>
#include <string>
#include "contact.h"
#include "contactbook.h"
#include <stdlib.h>
//#include <unistd.h>
using namespace std;
int main()
{
    contactbook users(100);
    int letter = -1;
    int choice;
    int search_type;
    int num = 0;
    cout << "\t\t:~ Welcome \n\n"
        << "\t\t__________\n";
    cout << "\t\t>>>>Choice List[1].>>>>\n"
        << "\t\t>>>>Exit[0].>>>>\n";
    cout << "Enter Your Choise : ";
    do
    {
        cin >> choice;
        system("cls");
        if (choice == 1)
        {
            while (letter != 0)
            {
                num = 0;
                cout << "\t\t1-Add New Contact\n"
                    << "\t\t2-Delete Contact\n"
                    << "\t\t3-Search For a Contact\n"
                    << "\t\t4-Display All Contacts\n"
                    << "\t\t5-Edit User\n"
                    << "\t\tEnter Your Choise\n"
                    << "\t\tIf You Want To Exit Enter 0\n"
                    << "------------------------\n";
                cout << "Enter : ";
                cin >> letter;
                system("cls");
                if (letter == 1)
                {
                    //add new contact
                    users.add();
                }
                if (letter == 2)
                {
                    //delete contact
                    cout << "Are You Sure To Delete ?\n"
                        << "Yes-[1]\n"
                        << "NO-[0]\n"
                        << "Enter your Choice : ";
                    int deleting;
                    cin >> deleting;
                    if (deleting)
                    users.Delete();
                }
                if (letter == 3)
                {
                    //search users
                    cout << "Search with :-\n"
                        << "Name->[1]\n"
                        << "City->[2]\n"
                        << "Phone->[3]\n";
                    cout << "Enter Your Choice : ";
                    cin >> search_type;
                    if (search_type == 1)
                    {
                        //***************************************************
                        cout << "Enter The Name To Search : ";
                        string sign;
                        cin.get();
                        getline(cin,sign);
                        users.research_names(sign);
                        if (users.research_names(sign) == true)
                        {
                            cout << "~Found\n";
                        }
                        else
                            cout << "~Not Found\n";
                    }
                    else if (search_type == 2)
                    {
                        cout << "Enter The City : ";
                        string city;
                        cin.get();
                        getline(cin, city);
                        if (users.research_city(city))
                        {
                            cout << "~Found\n";
                        }
                        else
                            cout << "~Not Found\n";
                    }
                    else if (search_type == 3)
                    {
                        string number;
                        cout << "Enter The Number : ";
                        cin >> number;
                        if (users.research_phone(number))
                        {
                            cout << "~Found\n";
                        }
                        else
                            cout << "~Not Found\n";
                    }
                }
                if (letter == 4)
                {
                    //display
                    users.show();
                }
                if (letter == 5)
                {
                    //Edit
                    users.Edit();
                }
                cout << "-------------------------------------------------------" << endl;
                //sleep(3);
                //system("cls");
            }
            cout << "Thank You :)";
        }
        else
            cout << "THANKS MY DEAR\n";
    } while (choice != 0&&choice<=5);
}