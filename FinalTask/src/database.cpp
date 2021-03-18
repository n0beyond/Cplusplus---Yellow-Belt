#include "database.h"

#include <algorithm>
#include <sstream>

using namespace std;

void Database::Add(const Date& date, const string& event)
{
	if (database_checker[date].count(event) == 0u)
	{
		database_checker[date].insert(event);
		database[date].push_back(event);
	}
}

void Database::Print(ostream& os) const
{
	for (const auto& [key, value] : database)
	{
		for (const auto& e : value)
		{
			os << key << " " << e << endl;
		}
	}
}

string Database::Last(const Date& date) const
{
	auto it = database.upper_bound(date);

	if (it == database.begin())
	{
		return "No entries";
	}

	stringstream ss;
	ss << (--it)->first << ' ' << it->second.back();

	return ss.str();
}

int Database::RemoveIf(const function<bool(Date, string)>& predicate)
{
	int count = 0;
	vector<Date> dates_to_delete;
	for (auto& [key, value] : database)
	{
		Date date = key;
		auto it = stable_partition(value.begin(), value.end(),
			[date, &predicate](string& event) {return !predicate(date, event); });

		count += value.end() - it;

		for (auto cur = it; cur != value.end(); cur++)
		{
			database_checker.at(key).erase(*cur);
		}

		value.erase(it, value.end());

		if (database[key].empty())
		{
			dates_to_delete.push_back(key);
		}
	}

	for (auto& date : dates_to_delete)
	{
		database.erase(date);
		database_checker.erase(date);
	}
	return count;
}