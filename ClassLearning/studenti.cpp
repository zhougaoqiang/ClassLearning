//studentc.cpp -- student class using containment

#include "pch.h"
#include "studenti.h"
#include <iostream>

using std::ostream;
using std::endl;
using std::istream;
using std::string;
using std::cin;
using std::cout;

//public methods
double student1::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

const string & student1::Name() const
{
	return (const string &) *this;
}

double & student1::operator[](int i)
{
	return ArrayDb::operator[](i);       //use valarray<double>::operator[]()
}

double student1::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

//private method
ostream & student1::arr_out(ostream & os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (1 % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << " empty array";
	return os;
}

//friends
//uses string version of operator>>()
istream & operator>>(istream & is, student1 & stu)
{
	is >> (string &)stu;
	return is;
}

//use string friend getline(ostream &, const string &
istream & getline(istream & is, student1 & stu)
{
	getline(is, (string &)stu);
	return is;
}

//use string version of operator<<{}
ostream & operator<<(ostream & os, const student1 & stu)
{
	os << "Scores for " << (const string &)stu << ": \n";
	stu.arr_out(os); //use private method for scores
	return os;
}

void use_stui() {

	const int pupils = 3;
	const int quizzes = 5;

	student1 ada[pupils] = { student1(quizzes), student1(quizzes), student1(quizzes) };

	int i;
	for (int i = 0; i < pupils; ++i)
		set1(ada[i], quizzes);

	cout << "\nStudent List: \n";
	for (int i = 0; i < pupils; ++i)
		cout << ada[i].Name() << endl;

	cout << "\nResults: ";
	for (int i = 0; i < pupils; ++i)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
	}

	cout << "Done. \n";
}

void set1(student1 & sa, int n) {
	cout << "Please enter the student's name: ";
	getline(cin, sa);
	cout << "Please enter " << n << "quiz score: \n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}