#include "pch.h"
#include "Worker0.h"
#include "workermi.h"
#include "stacktp.h"
#include "arraytp.h"
#include "tv.h"
#include "queuetp.h"
#include <iostream>
#include <string>
#include <cfloat>
void stacktem();
void twod();    //making a 2-D array
void nested();

void error2();
bool hmean(double a, double b, double *ans);

void error3();
double hmean(double a, double b);

int main()
{
	//worktest();
	//workmi();
	//stacktem();
	//twod();
	//use_tv();
	//nested();
	//error2();
	error3();
}

void stacktem() {
	Stack<std::string>st; //create an empty stack
	char ch;
	std::string po;

	cout << "Please enter A to add a purchase order, \n"
		<< "P to process a PO, or Q to quit. \n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << "\a";
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full \n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " popped\n";
				break;
			}
		}

		cout << "Please enter A to add a purchase oreder, \n"
			<< "P to process a PO, or Q to quit. \n";
	}
	cout << "Bye\n";
}
void twod()
{
	using std::cout;
	using std::endl;

	ArrayTP<int, 10> sums;
	ArrayTP<double, 10>aves;
	ArrayTP<ArrayTP<int, 8>, 10> twodee;

	int i, j;
	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;
		for (j = 0; j < 7; j++)
		{
			twodee[i][j] = (i + 1)*(j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 9;
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 7; j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": sum = ";
		cout.width(3);
		cout << sums[i] << ", average = " << aves[i] << endl;
	}

	cout << "Done.\n";
}
void nested()
{
	using std::string;
	using std::cin;
	using std::cout;

	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "Please enter your name. You will be "
			<< "served in the order of arrival.\n"
			<< "Name: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}

	cout << "The queue is full. Processing begins!\n";

	while (!cs.isfull())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << "...\n";
	}
}

void error2() {
	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		if (hmean(x, y, &z))
			std::cout << "Harmonic mean of " << x << " and " << y  //Harmonic mean 调和平均数
			<< " is " << z << std::endl;
		else
			std::cout << "One value should not be the negative "
			<< "of the other - try again. \n";
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
}
bool hmean(double a, double b, double *ans) {
	if (a == -b)
	{
		*ans = DBL_MAX;   //DBL_MAX 属于"cfloat", 是指 最大值
		return false;
	}
	else
	{
		*ans = 2.0*a*b / (a + b);
		return true;
	}
}

void error3() {
	double x, y, z;
	std::cout << "Enter two numbers: ";
	
	while (std::cin >> x >> y)
	{
		try                 //start of try block
		{
			z = hmean(x, y);
		}                   //end of try block
		catch (const char * s)   //start of exception handler
		{
			std::cout << s << std::endl;
			std::cout << "Enter a new pair of numbers: ";
			continue;
		}						//end of handler
		
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		std::cout << "Enter next set of numbers <q to quit>: ";
	}

	std::cout << "Bye\n";
}
double hmean(double a, double b) {
	if (a == -b)
		throw "bad hmean() arguments: a = -b not allowed";
	return 2.0*a*b /(a + b);
}