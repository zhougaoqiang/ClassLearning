#include "pch.h"
#include "mytime3.h"
#include <iostream>

Time3::Time3() {
	hours = mins = 0;
}

Time3::Time3(int h, int m) {
	hours = h;
	mins = m;
}

void Time3::AddMin(int m) {
	mins += m;
	hours += mins / 60;
	mins %= 60;
}
void Time3::AddHr(int h) {
	hours += h;
}
void Time3::Reset(int h, int m) {
	mins = m;
	hours = h;
}
Time3 Time3::operator+(const Time3 &t) const {
	Time3 sum;
	sum.mins = mins + t.mins;
	sum.hours = hours + t.hours + sum.mins / 60;
	sum.mins %= 60;
	return sum;
}
Time3 Time3::operator-(const Time3 &t) const {
	Time3 diff;
	int tot1, tot2;
	tot1 = t.mins + 60 * t.hours;    // tot1 指的是减数， 即 a-b 中的b；
	tot2 = mins + 60 * hours;		// tot1 指的是被减数， 即 a-b 中的a；
	diff.mins = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}
Time3 Time3::operator*(double n) const {
	Time3 result;

	long totalmins = hours * n * 60 + mins * n;
	result.hours = totalmins / 60;
	result.mins = totalmins % 60;

	return result;
}
std::ostream &operator << (std::ostream &os, const Time3 &t) {
	os << t.hours << "hours, " << t.mins << " minutes";
	return os;
}