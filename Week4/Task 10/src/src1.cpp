#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const char& prefix)
{
    string pref;
        pref += prefix;
    auto begin = lower_bound(range_begin, range_end, pref);
    pref[0]++;
    auto end = lower_bound(range_begin, range_end, pref);
    return {begin, end};
}