//Worker0.h -- working classes

#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker // an abstract base class
{
private:
	std::string fullname;
	long id;

public:
	Worker(): fullname(), id(0L) {}
	Worker(const std::string & s, long n) :fullname(s), id(n) {}
	virtual ~Worker() = 0; //pure virtual destructor
	virtual void Set();
	virtual void Show() const;
};

class Waiter : public Worker {
private: 
	int panache;
public:
	Waiter():Worker(),panache(0){}
	Waiter(const std::string & s, long n, int p = 0) :Worker(s,n), panache(p) {}
	Waiter(const Worker &wk, int p = 0) :Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};

class Singer :public Worker
{
protected:
	enum{other, alto, contralto, soprano, bass, baritone, tenor};
	enum {Vtypes = 7};

private:
	const char * pv[7]= { "other","alto","contralto","soprano","bass","baritone","tenor" };  //string equivs of voice types
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const std::string & s, long n, int v = other) : Worker(s, n), voice(v) {}
	Singer(const Worker &wk, int v = other) :Worker(wk), voice(v) {}
	void Set();
	void Show() const;
};

void worktest();

#endif // !WORKER_H_

