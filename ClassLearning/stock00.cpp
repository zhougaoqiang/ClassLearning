//stock00.cpp -- implementing the stock class
//version 00

#include "pch.h"
#include "stock00.h"
#include <iostream>

Stock::Stock() {
	std::cout << "Default constructor called\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const std::string & co, long n, double pr) {
	std::cout << "Constructor using " << co << "called\n";
	company = co;

	if (n < 0) {
		std::cout << "NUmber of shares can't be negative;"
			<< company << " shares set to 0. \n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock()  //verbose class destructor
{
	// std::cout << "Bye, " << company << "!\n";  //隐藏
}
void Stock::buy(long num, double price) {
	if (num < 0) {
		std::cout << "Number os shares purchased can't be negative."
			<< "Transaction is aborted. \n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price) {
	using std::cout;

	if (num < 0)
	{
		cout << "Number os shares purchased can't be negative."
			<< "Transaction is aborted. \n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have!"
			<< "Transaction is aborted. \n";
	}
	else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price) {
	share_val = price;
	set_tot();
}
void Stock::show() const {     //Stock::show() const <-保证Show不能改变调用对象的值。
	using std::cout;
	using std::ios_base;

	//set format to #.###
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "Company: " << company
		<< " Shares: " << shares << '\n';
	cout << " Share Price: $" << share_val;

	//set format to #.##
	cout.precision(2);
	cout << " Total Worth: $" << total_val << '\n';

	//restore original format
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const			// const Stock [返回Stock] &Stock ::topval
{
	if (s.total_val > total_val)
		return s;		//argument object参数对象
	else
		return *this;   //invoking object调用对象
}