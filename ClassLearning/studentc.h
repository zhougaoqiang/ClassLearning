//studentc.h -- defineing a student class using containment

#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class student {
private:
	typedef std::valarray<double> ArrayDb;
	std::string name; //contained object
	ArrayDb scores;   //contained object
	//private method for scores output
	std::ostream & arr_out(std::ostream & os) const;
public:
	student() :name("Null Student"), scores() {}
	explicit student (const std::string &s):name(s), scores(){}    //explicitÃ÷È·µÄ
	explicit student (int n):name("Nully"), scores(n){}
	student (const std::string & s, int n): name(s), scores(n) {}
	student (const std::string & s, const ArrayDb & a): name(s), scores(a){}
	student (const char * str, const double * pd, int n): name(str), scores(pd, n){}
	~student() {}

	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);
	double operator[](int i) const;

	//friends
	//input:
	friend std::istream & operator >> (std::istream & is, student &stu);   //1 word
	friend std::istream & getline(std::istream & is, student & stu); //1 line

	//output:
	friend std::ostream & operator<<(std::ostream & os, const student & stu);
};

void use_stuc();
void set(student & sa, int n);
#endif // !STUDENTC_H_

