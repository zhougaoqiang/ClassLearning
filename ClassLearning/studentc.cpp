//studentc.cpp -- student class using containment

#include "pch.h"
#include "studentc.h"
#include <iostream>

using std::ostream;
using std::endl;
using std::istream;
using std::string;

//public methods
double student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}

const string & student::Name() const
{
	return name;
}

double & student::operator[](int i)
{
	return scores[i];       //use valarray<double>::operator[]()
}

double student::operator[](int i) const
{
	return scores[i];
}

//private method
ostream & student::arr_out(ostream & os) const
{
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
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
istream & operator>>(istream & is, student & stu)
{
	is >> stu.name;
	return is;
}

//use string friend getline(ostream &, const string &
istream & getline(istream & is, student & stu)
{
	getline(is, stu.name);
	return is;
}

//use string version of operator<<{}
ostream & operator<<(ostream & os, const student & stu)
{
	os << "Scores for " << stu.name << ": \n";
	stu.arr_out(os); //use private method for scores
	return os;
}

void use_stuc() {
	using std::cin;
	using std::cout;
	using std::endl;
	
	const int pupils = 3;
	const int quizzes = 5;

	student ada[pupils] = { student(quizzes), student(quizzes), student(quizzes) };

	int i;
	for (int i = 0; i < pupils; ++i)
		set(ada[i], quizzes);

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

void set(student & sa, int n) {
	std::cout << "Please enter the student's name: ";
	getline(std::cin, sa);
	std::cout << "Please enter " << n << "quiz score: \n";
	for (int i = 0; i < n; i++)
		std::cin >> sa[i];
	while (std::cin.get() != '\n')
		continue;
}