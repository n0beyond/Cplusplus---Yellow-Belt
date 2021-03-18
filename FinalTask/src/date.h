#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Date
{
public:
	Date(int year_, int month_, int day_);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

private:
	const int year, month, day;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);