//============================================================================
// Name        : Hashing.cpp
// Author      : Reet
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class client
{
	int phone;
	string name;
public:
	client()
	{
		phone = -1;
		name = "N/A";
	}
	client(int phone, string name)
	{
		this->phone = phone;
		this->name = name;
	}
	friend class hash1;
};

class hash1
{
	client cl[10];
public:
	hash1();
	void display();
	void LPwR(int, string);
	void LP(int, string);
};

hash1::hash1()
{
	for(int i = 0; i < 10; i++)
	{
		cl[i].phone = -1;
		cl[i].name = "N/A";
	}
}

void hash1::LP(int phone, string name)
{
	int dig = phone%10;
	if(cl[dig].phone == -1)
	{
		cl[dig].phone = phone;
		cl[dig].name = name;
	}
	else
	{
		int temp = dig+1;
		while(temp < 10)
		{
			if(cl[temp].phone == -1)
			{
				cl[temp].phone = phone;
				cl[temp].name = name;
				return;
			}
			temp++;
		}
		temp = 0;
		while(temp < dig)
		{
			if(cl[temp].phone == -1)
			{
				cl[temp].phone = phone;
				cl[temp].name = name;
				return;
			}
			temp++;
		}
	}
}

void hash1::LPwR(int phone, string name)
{
	int dig = phone%10;
	if(cl[dig].phone%10 != dig)
	{
		int temp1 = cl[dig].phone;
		string temp2 = cl[dig].name;
		cl[dig].phone = phone;
		cl[dig].name = name;
		LP(temp1, temp2);
	}
	else
	{
		LP(phone, name);
	}
}


void hash1::display()
{
	for(int i = 0; i < 10; i++)
	{
		cout<<"\n"<<i<<" "<<cl[i].phone<<" "<<cl[i].name;
	}
}

int main()
{
	hash1 obj;
	int option, phone, size1 = 0, size2 = 0;
	string name;
	char ch = 'Y', ch2, op2;
	do
	{
		label1:
		cout <<"\nS.NO.	Operation\n";
		cout<<"1.	Linear Probing\n";
		cout<<"2.	Linear Probing with Replacement\n";
		cout<<"3.	Exit\n";
		cout<<"Please enter an option.\nOption: ";
		cin>>option;
		switch(option)
		{
			case 1:
				do
				{
					cout<<"OPTION 1: Linear Probing\n";
					cout <<"\nS.NO.	Operation\n";
					cout<<"A.	Insert Element\n";
					cout<<"B.	Display Hash Table\n";
					cout<<"C.	Exit\n";
					cout<<"Please enter an option.\nOption: ";
					cin>>op2;
					switch(op2)
					{
					case 'A':
						if(size1 < 10)
						{
							cout<<"\nPlease enter the phone number and name.\nPhone No.: ";
							cin>>phone;
							cin.ignore();
							cout<<"Name: ";
							cin>>name;
							obj.LP(phone, name);
							cout<<"\nElement has been inserted.\n";
						}
						else
						{
							cout<<"\nThe Hash Table is full.\nYou cannot insert any elements.";
						}
						break;
					case 'B':
						obj.display();
						break;
					case 'C':
						cout<<"\nExiting from Sub Menu...";
						goto label1;
						break;
					default:
						cout<<"\nInvalid Option";
						break;
					}
					cout<<"\nDo you want to continue? (Y/N)\n";
					cin>>ch2;
				}while(ch2 == 'Y' || ch2 == 'y');
				break;
			case 2:
				do
				{
					cout<<"OPTION 2: Linear Probing with Replacement\n";
					cout <<"\nS.NO.	Operation\n";
					cout<<"A.	Insert Element\n";
					cout<<"B.	Display Hash Table\n";
					cout<<"C.	Exit\n";
					cout<<"Please enter an option.\nOption: ";
					cin>>op2;
					switch(op2)
					{
					case 'A':
						if(size2 < 10)
						{
							cout<<"\nPlease enter the phone number and name.\nPhone No.: ";
							cin>>phone;
							cin.ignore();
							cout<<"Name: ";
							cin>>name;
							obj.LP(phone, name);
							cout<<"\nElement has been inserted.\n";
						}
						else
						{
							cout<<"\nThe Hash Table is full.\nYou cannot insert any elements.";
						}
						break;
					case 'B':
						obj.display();
						break;
					case 'C':
						cout<<"\nExiting from Sub Menu...";
						goto label1;
						break;
					default:
						cout<<"\nInvalid Option";
						break;
					}
					cout<<"\nDo you want to continue? (Y/N)\n";
					cin>>ch2;
				}while(ch2 == 'Y' || ch2 == 'y');
				break;
			case 3:
				cout<<"\nExiting...";
				return 0;
				break;
			default:
				cout<<"\nInvalid Option";
				break;
		}
		cout<<"\nDo you want to continue? (Y/N)\n";
		cin>>ch;
	}while(ch == 'Y' || ch == 'y');
	return 0;
}
