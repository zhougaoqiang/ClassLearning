//workermi.cpp -- working class methods with MI

#include "pch.h"
#include "workermi.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

//worker methods
Worker1::~Worker1() {}

//protected methods
void Worker1::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee: " << id << endl;
}

void Worker1::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

//Waiter methods
void Waiter1::Set()
{
	cout << "Enter waiter's name: ";
	Worker1::Get();
	Get();
}

void Waiter1::Show() const
{
	cout << "Category: waiter\n";
	Worker1::Data();
	Data();
}

//Protected methods
void Waiter1::Data() const
{
	cout << "Panache rating: " << panache << endl;
}

void Waiter1::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

//Singer methods
void Singer1::Set()
{
	cout << "Enter singer's name: ";
	Worker1::Get();
	Get();
}

void Singer1::Show() const
{
	cout << "Category: singer\n";
	Worker1::Data();
	Data();
}

//protected mthods
void Singer1::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer1::Get()
{
	cout << "Enter number for singer's vocal range: \n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "  ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

//SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer1::Data();
	Waiter1::Data();
}

void SingingWaiter::Get()
{
	Waiter1::Get();
	Singer1::Get();
}

void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker1::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Category: Singingwaiter\n";
	Worker1::Data();
	Data();
}

void workmi() {
	const int SIZE = 5;
	using std::strchr;

	Worker1 *lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the empolyee category: \n"
			<< "w: Waiter   s:Singer  "
			<< "t: Singingwaiter   q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}

		if (choice == 'q')
			break;

		switch (choice)
		{
		case 'w': lolas[ct] = new Waiter1;
			break;
		case 's': lolas[ct] = new Singer1;
			break;
		case 't': lolas[ct] = new SingingWaiter;
			break;
		}

		cin.get();
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];

	cout << "Bye.\n";
}