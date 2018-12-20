//start to open all test functions

#include "pch.h";
#include "mytime0.h";
#include "mytime1.h";
#include "mytime3.h";
#include <iostream>;

using std::cout;
using std::endl;

void usetime0();
void usetime1();
void usetime2();
void usetime3();

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
	usetime3();
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