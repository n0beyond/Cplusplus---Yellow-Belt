#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border)
{
    const auto first_last_less = numbers.lower_bound(border);
    if (first_last_less == numbers.begin())
    {
        return first_last_less;
    }

    const auto last_less = prev(first_last_less);
    if (first_last_less == numbers.end())
    {
        return last_less;
    }

    if (border - *last_less <= *first_last_less - border)
    {
        return last_less;
    }
    else
    {
        return first_last_less;
    }
}