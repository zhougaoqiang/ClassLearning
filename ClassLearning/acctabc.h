//acctabc.h -- bank account classes

#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

//abstract Base class
class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName() const { return fullName; }
	long AcctNum() const { return acctNum; }
	Formatting setFormat() const;
	void Restore(Formatting & f) const;
public: 
	AcctABC(const std::string & s = "Nullbody", long an = -1, double ba = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;   //pure virtual function
	double Balance() const { return balance; };
	virtual void ViewAcct() const = 0;      //pure virtual function
	virtual ~AcctABC() {}
};


//Brass Account Class
class Brass1 : public AcctABC
{
public:
	Brass1(const std::string & s = "Nullbody", long an = -1, double bal = 0.0):
		AcctABC(s, an, bal){}

	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass1(){}
};

//Brass Plus Account class
class BrassPlus1 : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus1(const std::string & s = "nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus1(const Brass1 & ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; };
	void ResetRate(double r) { rate = r; };
	void ResetOwes() { owesBank = 0; };
};

void usebrass3();
#endif // !ACCTABC_H_

