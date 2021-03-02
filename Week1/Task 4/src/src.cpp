#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

int FindMaxRepetitionCount(const vector<Region>& regions)
{
    map<Region, int> counts;
    for(const auto& item : regions)
    {
        counts[item]++;
    }
    if (regions.size() == 0u) 
    {
        return 0;
    }
    int maxcnt = 0;
    for(const Region& item : regions)
    {
        maxcnt = max(maxcnt, counts[item]);
    }
    return maxcnt;
}

bool operator <(const Region& lhs, const Region& rhs)
{
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
            tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}