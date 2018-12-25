//workermi.h -- working classes with MI
#ifndef WORKMI_H_
#define WORKMI_H_

#include<string>

class Worker1 // an abstract base class
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker1() : fullname("No One"), id(0L) {}
	Worker1(const std::string & s, long n) :fullname(s), id(n) {}
	virtual ~Worker1() = 0; //pure virtual destructor
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter1 : virtual public Worker1{
private:
	int panache;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Waiter1() :Worker1(), panache(0) {}
	Waiter1(const std::string & s, long n, int p = 0) :Worker1(s, n), panache(p) {}
	Waiter1(const Worker1 &wk, int p = 0) :Worker1(wk), panache(p) {}
	void Set();
	void Show() const;
};

class Singer1 : virtual public Worker1
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	virtual void Data() const;
	virtual void Get();
private:
	const char * pv[7] = { "other","alto","contralto","soprano","bass","baritone","tenor" };  //string equivs of voice types
	int voice;
public:
	Singer1() : Worker1(), voice(other) {}
	Singer1(const std::string & s, long n, int v = other) 
		: Worker1(s, n), voice(v) {}
	Singer1(const Worker1 &wk, int v = other) 
		:Worker1(wk), voice(v) {}
	void Set();
	void Show() const;
};

//multiple inheritance
class SingingWaiter : public Singer1, public Waiter1
{
protected:
	virtual void Data() const;
	virtual void Get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
		: Worker1(s, n), Waiter1(s, n, p), Singer1(s, n, v){}
	SingingWaiter(const Worker1 & wk, int p = 0, int v = other)
		:Worker1(wk), Waiter1(wk, p), Singer1(wk, v) {}
	SingingWaiter(const Waiter1 & wt, int v = other)
		:Worker1(wt), Waiter1(wt), Singer1(wt, v) {}
	SingingWaiter(const Singer1 & wt, int p = 0)
		:Worker1(wt), Waiter1(wt, p), Singer1(wt) {}
	void Set();
	void Show() const;
};


void workmi();
#endif // !WORKMI_H_

