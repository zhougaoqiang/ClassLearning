//mytime0.h -- Time class before operator overloading

#ifndef MYTIME0_H_

#define MYTIME0_H_

class Time0
{
private:
	int hours;
	int mins;
public:
	Time0();
	Time0(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time0 Sum(const Time0 &t) const;
	void show()const;
};

#endif // !MYTIME0_H_
