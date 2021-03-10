#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        firstnames[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name)
    {
        lastnames[year] = last_name;
    }
    string GetFullName(int year)
    {
        string fname, lname;
        if (firstnames.upper_bound(year) != firstnames.begin())
        {
            fname = prev(firstnames.upper_bound(year))->second;
        }

        if (lastnames.upper_bound(year) != lastnames.begin())
        {
            lname = prev(lastnames.upper_bound(year))->second;
        }

        if (fname.empty() && lname.empty())
        {
            return "Incognito";
        }
        else if (fname.empty())
        {
            return (lname + " with unknown first name");
        }
        else if (lname.empty())
        {
            return (fname + " with unknown last name");
        }
        else
        {
            return (fname + " " + lname);
        }
    }
private:
    map<int, string> firstnames, lastnames;
};