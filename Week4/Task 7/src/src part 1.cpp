#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin < 2)
	{
		return;
	}
	vector<typename RandomIt::value_type> v(range_begin, range_end);
	MergeSort(v.begin(), v.begin() + v.size() / 2);
	MergeSort(v.begin() + v.size() / 2, v.end());
	merge(v.begin(), v.begin() + v.size() / 2, v.begin() + v.size() / 2, v.end(), range_begin);
}