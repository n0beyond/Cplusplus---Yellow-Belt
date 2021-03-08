#include "phone_number.h"
#include <stdexcept>

using namespace std;

PhoneNumber::PhoneNumber(const string& international_number)
{
	if (international_number[0] != '+')
	{
		throw invalid_argument("");
	}
	int count = 0;
	for (const char& c : international_number)
	{
		if (c == '-')
		{
			++count;
		}
		if (count == 0)
		{
			if (c != '+')
			{
				country_code_ += c;
			}
		}
		else if (count == 1)
		{
			if (c != '-')
			{
				city_code_ += c;
			}
		}
		else
		{
			if (count != 2)
			{
				local_number_ += c;
			}
			count++;
		}
	}
	if (!country_code_.size() || !city_code_.size()
		|| !local_number_.size())
	{
		throw invalid_argument("");
	}
}

string PhoneNumber::GetCountryCode() const
{
	return country_code_;
}

string PhoneNumber::GetCityCode() const
{
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
    return "+" + GetCountryCode() + "-" + GetCityCode() + "-" + GetLocalNumber();
}
    
