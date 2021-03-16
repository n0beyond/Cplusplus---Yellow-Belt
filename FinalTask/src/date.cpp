#include <date.h>

using namespace std;

class Date
{
public:
	Date(int year_, int month_, int day_) 
		: year(year_), month(month_), day(day_) {}

	int GetYear()
	{
		return year;
	}
	int GetYear()
	{
		return month;
	}
	int GetDay()
	{
		return day;
	}

private:
	const int year, month, day;
};

Date ParseDate(istream& is)
{
	string str;
    is >> str;
    int year, month, day;
	stringstream ss;

	ss >> year;
	ss.ignore(1);
	ss >> month;
	ss.ignore(1);
	ss >> day;
    return (Date(year, month, day));
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << setfill('0');
	os << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();
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

bool operator==(const Date& lhs, const Date& rhs)
{
	return (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}