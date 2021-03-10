#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin < 3)
	{
		return;
	}
	vector<typename RandomIt::value_type> v(range_begin, range_end);
	MergeSort(v.begin(), v.begin() + v.size() / 3);
	MergeSort(v.begin() + v.size() / 3, v.begin() + v.size() * 2 / 3);
	MergeSort(v.begin() + v.size() * 2 / 3, v.end());
	vector<typename RandomIt::value_type> s;
	merge(v.begin(), v.begin() + v.size() / 3, v.begin() + v.size() / 3, v.begin() + v.size() * 2 / 3, back_inserter(s));
	merge(s.begin(), s.end(), v.begin() + v.size() * 2 / 3, v.end(), range_begin);
}
