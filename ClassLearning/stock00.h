//stock00.h --stock class interface
//version 00

#ifndef STOCK00_H_
#define STOCK00_H_

#include "pch.h"
#include <string>

class Stock //class declaration
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock(); //default constructor
	Stock(const std::string &co, long n, double pr);
	~Stock(); //noisy constructor
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock & topval(const Stock & s) const;
};    //note semicolon at the end

#endif
