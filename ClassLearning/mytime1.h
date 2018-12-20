#ifndef MYTIME1_H_

#define MYTIME1_H_

class Time1
{
private:
	int hours;
	int mins;
public:
	Time1();
	Time1(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time1 operator+(const Time1 &t) const;
	Time1 operator-(const Time1 &t) const;
	Time1 operator*(double n) const;
	void show()const;
};

#endif // !MYTIME1_H_
#pragma once

