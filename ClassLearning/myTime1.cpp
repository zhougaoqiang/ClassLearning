#include "pch.h"
#include "mytime1.h"
#include <iostream>

Time1::Time1() {
	hours = mins = 0;
}

Time1::Time1(int h, int m) {
	hours = h;
	mins = m;
}

void Time1::AddMin(int m) {
	mins += m;
	hours += mins / 60;
	mins %= 60;
}
void Time1::AddHr(int h) {
	hours += h;
}
void Time1::Reset(int h, int m) {
	mins = m;
	hours = h;
}
Time1 Time1::operator+(const Time1 &t) const {
	Time1 sum;
	sum.mins = mins + t.mins;
	sum.hours = hours + t.hours + sum.mins / 60;
	sum.mins %= 60;
	return sum;
}
Time1 Time1::operator-(const Time1 &t) const {
	Time1 diff;
	int tot1, tot2;
	tot1 = t.mins + 60 * t.hours;    // tot1 指的是减数， 即 a-b 中的b；
	tot2 = mins + 60 * hours;		// tot1 指的是被减数， 即 a-b 中的a；
	diff.mins = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}
Time1 Time1::operator*(double n) const {
	Time1 result;
	
	long totalmins = hours * n * 60 + mins * n;
	result.hours = totalmins / 60;
	result.mins = totalmins % 60;

	return result;
}
void Time1::show()const {
	std::cout << hours << " hours, " << mins << " minutes";
}