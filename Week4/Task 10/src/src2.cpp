#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix)
{
    string pref = prefix;
    auto begin = lower_bound(range_begin, range_end, pref);
    pref[pref.size() - 1]++;
    auto end = lower_bound(range_begin, range_end, pref);
    return {begin, end};
}