//start to open all test functions

#include "pch.h"
#include "mytime0.h";
#include "mytime1.h";
#include "mytime3.h";
#include "vect.h";
#include "stonewh.h";
#include "string1.h"
#include <iostream>;
#include <ctime>;
#include <cstdlib>;

using std::cout;
using std::cin;
using std::endl;

void usetime0();
void usetime1();
void usetime2();
void usetime3();
void randwalk();

void stone();
void display(const Stonewt &st, int n);

void sayings1();

int main() {
	/*
	usetime0();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	usetime1();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	usetime2();
	*/
	//usetime3();
	//randwalk();
	//stone();
	sayings1();
}

void usetime0() {


	Time0 Planning;
	Time0 coding(2, 40);
	Time0 fixing(5, 55);
	Time0 total;

	cout << "Planning time = ";
	Planning.show();
	cout<<endl;

	cout << " coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;


	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.show();
	cout << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << endl;
	cout << " coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;
}

void usetime1() {
	Time1 Planning;
	Time1 coding(3, 50);
	Time1 fixing(4, 55);
	Time1 total;

	cout << "Planning time = ";
	Planning.show();
	cout << endl;

	cout << " coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;


	total = coding + fixing;
	cout << "coding.Sum(fixing) = ";
	total.show();
	cout << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << endl;
	cout << " coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;
}
void usetime2() {
	Time1 weeding(4, 35);
	Time1 waxing(2, 47);
	Time1 total;
	Time1 diff;
	Time1 diff2;
	Time1 adjusted;

	cout << "weeding time = ";
	weeding.show();
	cout << endl;

	cout << "waxing time = ";
	waxing.show();
	cout << endl;

	cout << "total work time = ";
	diff = weeding + waxing;	// use operator +
	total.show();
	cout << endl;

	cout << "weeding time - waxing time = ";
		diff = weeding - waxing;	// use operator -
	diff.show();
	cout << endl;

	cout << " waxing time - weeding time = ";
	diff2 = waxing - weeding;	// use operator -
	diff2.show();
	cout << endl;

	adjusted = total * 1.5; //use operator *
	cout << "adjusted working time = ";
	adjusted.show();
	cout << endl;
}
void usetime3() {
	Time3 aida(3, 25); 
	Time3 tosca(2, 48);
	Time3 temp;

	cout << "Aida and Tosca: \n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca; //operator+()
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17; //member operator *()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0*tosca << endl;
}
void randwalk() {
	using VECTOR::Vector;
	srand(time(0));  //seed random-number generator;

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (std::cin >> target)
	{
		cout << "Enter step length: ";
		if (!(std::cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			<< "has the following location: \n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}

	cout << "Bye!\n";
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
}
void stone() {
	Stonewt incognito = 275;  //use constructor to initialize
	Stonewt wolfe(285.7);  //same as Stonewt wolfe = 285.7
	Stonewt taft(21, 8);

	cout << "The celebrity weighed ";
	incognito.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	cout << "The President weighed ";
	taft.show_lbs();
	
	incognito = 276.8; //uses constructor for onversion
	taft = 325; //same as taft = Stonewt(325)
	cout << "After dinner, the celebrity weighed ";
	incognito.show_stn();
	cout << "After dinner, the President weighed ";
	taft.show_lbs();

	display(taft, 2);
	cout << "The wrestler weighed even more. \n";
	display(422, 2);
	cout << "No Stone left unearned\n";
}
void display(const Stonewt &st, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Wow!";
		st.show_stn();
	}
}

void sayings1() {
	const int ArSize = 10;
	const int MaxLen = 81;

	String name;
	cout << "Hi,what's your name?\n>>";
	cin >> name;

	cout << name << ", please enter up to " << ArSize
		<< " shorts sayings <empty line to quit>: \n";
	String sayings[ArSize]; //array of objects
	char temp[MaxLen];		//temporary string storage
	int i;
	for (i = 0; i < ArSize; i++) 
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')		//empty line
			break;			//i not incremented
		else
			sayings[i] = temp; //overloaded assignment
	}

	int total = i;		//total # of line read

	if (total > 0)
	{
		cout << "Here are your sayings: \n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;

		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}

		cout << "Short saying: \n" << sayings[shortest] << endl;
		cout << "First alphabetically: \n" << sayings[first] << endl;
		cout << "This program used " << String::HowMany()
			<< " String objects. Bye.\n";
	}
	else
		cout << "No input! Bye.\n";
}