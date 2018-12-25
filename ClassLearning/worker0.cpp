//worker0.cpp -- working class methods

#include "pch.h"
#include "Worker0.h"
#include <iostream>

using std::endl;
using std::cin;
using std::cout;

//worker methods

//must implement virtual destructor, even if pure
Worker::~Worker() {}

void Worker::Set()
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Worker::Show() const
{
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID: " << id << "\n";
}

//waiter methods
void Waiter::Set()
{
	Worker::Set();
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Show() const
{
	cout << "Category: Waiter\n";
	Worker::Show();
	cout << "Panache rating: " << panache << "\n";
}

//Singer methods

void Singer::Set()
{
	Worker::Set();
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
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "Please enter a value >= 0 and <" << Vtypes << endl;

	while (cin.get() != '\n')
		continue;
}

void Singer::Show() const
{
	cout << "Category: singer \n";
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}

void worktest()
{
	const int LIM = 4;

	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;

	Worker *pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->Set();

	for (i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
}