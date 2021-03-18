#include "date.h"

using namespace std;

Date::Date(int year_, int month_, int day_)
	: year(year_), month(month_), day(day_) {}

int Date::GetYear() const
{
	return year;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetDay() const
{
	return day;
}

Date ParseDate(istream& is)
{
    int year, month, day;

	is >> year;
	is.ignore(1);
	is >> month;
	is.ignore(1);
	is >> day;
    return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << setfill('0');
	os << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth() << "-" << setw(2) << date.GetDay();
	return os;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return(lhs.GetDay() < rhs.GetDay());
		}

		return(lhs.GetMonth() < rhs.GetMonth());
	}
	return(lhs.GetYear() < rhs.GetYear());
}

bool operator<=(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() <= rhs.GetDay();
		}

		return lhs.GetMonth() < rhs.GetMonth();
	}

	return lhs.GetYear() < rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return lhs.GetYear() != rhs.GetYear() || lhs.GetMonth() != rhs.GetMonth() || lhs.GetDay() != rhs.GetDay();
}

bool operator>(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() > rhs.GetDay();
		}

		return lhs.GetMonth() > rhs.GetMonth();
	}

	return lhs.GetYear() > rhs.GetYear();
}

bool operator>=(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() >= rhs.GetDay();
		}

		return lhs.GetMonth() > rhs.GetMonth();
	}

	return lhs.GetYear() > rhs.GetYear();
}