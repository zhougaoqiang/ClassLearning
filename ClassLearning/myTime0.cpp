//mytime0.cpp -- implementing Time methods

#include "pch.h"
#include "mytime0.h"
#include <iostream>

Time0::Time0() {
	hours = mins = 0;
}

Time0::Time0(int h, int m) {
	hours = h;
	mins = m;
}

void Time0::AddMin(int m) {
	mins += m;
	hours += mins / 60;
	mins %= 60;
}
void Time0::AddHr(int h) {
	hours += h;
}
void Time0::Reset(int h, int m) {
	mins = m;
	hours = h;
}
Time0 Time0::Sum(const Time0 &t) const {
	Time0 sum;
	sum.mins = mins + t.mins;
	sum.hours = hours + t.hours + sum.mins / 60;
	sum.mins %= 60;
	return sum;
}
void Time0::show()const {
	std::cout << hours << " hours, " << mins << " minutes";
}