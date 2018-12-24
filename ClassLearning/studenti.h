//studenti.h -- defineing a student class using containment

#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <string>
#include <valarray>

class student1: private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	//private method for scores output
	std::ostream & arr_out(std::ostream & os) const;
public:
	student1() :std::string("Null Student"), ArrayDb() {};
	explicit student1(const std::string &s) :std::string(s),ArrayDb(){}    //explicitÃ÷È·µÄ
	explicit student1(int n) :std::string("Nully"), ArrayDb(){}
	student1(const std::string & s, int n) : std::string(s), ArrayDb(n) {}
	student1(const std::string & s, const ArrayDb & a) : std::string(s), ArrayDb(a) {}
	student1(const char * str, const double * pd, int n) : std::string(str), ArrayDb(pd, n) {}
	~student1() {}

	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);
	double operator[](int i) const;

	//friends
	//input:
	friend std::istream & operator >> (std::istream & is, student1 &stu);   //1 word
	friend std::istream & getline(std::istream & is, student1 & stu); //1 line

	//output:
	friend std::ostream & operator<<(std::ostream & os, const student1 & stu);
};

void use_stui();
void set1(student1 & sa, int n);
#endif // !STUDENTI_H_


