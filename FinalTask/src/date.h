#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class Date
{
public:
	Date(int year_, int month_, int day_)
		: year(year_), month(month_), day(day_) {}

	int GetYear();
	int GetMonth();
	int GetDay();

private:
	const int year, month, day;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);