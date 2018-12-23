//acctabc.cpp -- bank account class methods
#include "pch.h"
#include "acctabc.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::ios_base;
using std::endl;
using std::string;

//Abstract Base class
AcctABC::AcctABC(const string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposite not allowed;"
		<< "deposit is cancelled. \n";
	else
		balance += amt;
}

void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}

// protected methods for formatting
AcctABC::Formatting AcctABC::setFormat() const
{
	//set uo ###.## format
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting &f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}

//Brass1 methos
void Brass1::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Withdrawak amount must be positive; "
		<< "Withdrawal canceled. \n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Withdrawal amount of $" << amt
		<< " exceeds your balance.\n"
		<< "withdrawal canceled. \n";
}

void Brass1::ViewAcct() const
{
	Formatting f = setFormat();
	cout << "Brass1 Client: " << FullName() << endl;
	cout << "Account Number: " << AcctNum() << endl;
	cout << "Balance: $" << Balance() << endl;
	Restore(f);
}

//BrassPlus1 Methods
BrassPlus1::BrassPlus1(const string & s, long an, double bal, double ml, double r) :
	AcctABC(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus1::BrassPlus1(const Brass1 &ba, double ml, double r) :
	AcctABC(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus1::ViewAcct() const
{
	Formatting f = setFormat();

	cout << "Brass1 Client: " << FullName() << endl;
	cout << "Account Number: " << AcctNum() << endl;
	cout << "Balance: $" << Balance() << endl;
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan rate: " << 100 * rate << "%\n";
	Restore(f);
}

void BrassPlus1::Withdraw(double amt)
{
	Formatting f = setFormat();

	double bal = Balance();
	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 * rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	Restore(f);
}

void usebrass3() {
	const int CLIENTS = 4;

	AcctABC *P_CLients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		getline(cin, temp);
		cout << "Enter client's accout number: ";
		cin >> tempnum;
		cout << "Enter opening balance: $";
		cin >> tempbal;
		cout << "Enter 1 for Brass1 Account or "
			<< "a for BrassPlus1 Account: ";

		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";

		if (kind == '1')
			P_CLients[i] = new Brass1(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cout << "Enter the interest rate as a decimal fraction: ";
			cin >> trate;
			P_CLients[i] = new BrassPlus1(temp, tempnum, tempbal, tmax, trate);
		}

		while (cin.get() != '\n')
			continue;
	}

	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		P_CLients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete P_CLients[i]; //free memory
	}

	cout << "Done. \n";
}