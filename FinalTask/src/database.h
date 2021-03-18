#pragma once

#include "date.h"

#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

class Database
{
public:
	void Add(const Date& date, const string& event);
	void Print(ostream& os) const;

	int RemoveIf(const function<bool(Date, string)>& predicate);

	template <typename F>
	vector<pair<Date, string>> FindIf(const F predicate) const;

	string Last(const Date& date) const;
private:
	map<Date, vector<string>> database;
	map<Date, set<string>> database_checker;
};

template <typename F>
vector<pair<Date, string>> Database::FindIf(const F predicate) const
{
	vector<pair<Date, string>> res;

	for (auto& [key, value] : database)
	{
		for (size_t i = 0; i < value.size(); i++)
		{
			if (predicate(key, value[i]))
			{
				res.push_back(make_pair(key, value[i]));
			}
		}
	}

	return res;
}
