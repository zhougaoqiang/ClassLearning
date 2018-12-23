//brass.cpp -- bank account class methods
#include "pch.h"
#include "brass.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//formattin stuff
typedef std::ios_base::fmtflags format; 
typedef std::streamsize precis; //精确
format setFormat();
void restore(format f, precis p);

Brass::Brass(const string & s, long an, double bal)
{
	full_name = s;
	accountNum = an;
	balance = bal;
}

void Brass::Deposit(double amt) {
	if (amt < 0)
		cout << "Negative deposit not allowed; "
		<< "deposit is cancelled. \n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "Negative deposit not allowed; "
		<< "deposit is cancelled. \n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		<< " exceeds your balance.\n"
		<< "Withdrawak canceled. \n";
	restore(initialState, prec);
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	//set up to ###.##format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << full_name << endl;
	cout << "Account Number: " << accountNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);    //restore original format
}

//BrassPlus Methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) :
	Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
	:Brass(ba)   //uses implicit copy constructor使用隐式复制构造函数
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

//redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
	//set up to ###.##format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct(); //display base portion 派生类可以调用基类的方法
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);  //###.### format
	cout << "Loan Rate: " << 100 * rate << "%\n";
	restore(initialState, prec);
}

//redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
	//set up to ###.##format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charage: $" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled. \n";

	restore(initialState, prec);
}

format setFormat()
{
	//set up ###.## format
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}

void usebrass1() {
	Brass Piggy("Procelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Hogg Account: \n";
	Hoggy.Deposit(1000.00);
	cout << "New balance: $" << Hoggy.Balance() << endl;
	cout << "Withdrawing $ from the Pigg.Balance()" << endl;
	Piggy.Withdraw(4200.00);
	cout << "Pigg account balance: $" << Piggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Hogg Account: \n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
}
void usebrass2() {				//演示虚方法的行为
	const int CLIENTS = 4;

	Brass *p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		getline(cin, temp);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening balance: $";
		cin >> tempbal;
		cout << "Enter 1 for Brass Account or"
			<< "2 for BrassPlus Account: ";

		while (cin >> kind && (kind != '1' && kind != '2'))
		{
			cout << "Enter either 1 or 2: ";
		}

		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);   //选项1会使用Brass对象
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cout << "Enter the interest rate "
				<< "as a decimal fraction: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate); //选项2使用BrassPlus对象
		}
		while (cin.get() != '\n')
			continue;
	}

	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();   //多态性由此代码提供
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i]; //free memory
	}
	cout << "Done. \n";
}