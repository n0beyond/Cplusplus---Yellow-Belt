#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
	vector<T> v;
	auto it = find_if(elements.begin(), elements.end(),
		[&, border](const T& something) { return something > border; });
	for (auto i = it; i != elements.end(); i++)
	{
		v.push_back(*i);
	}
	return v;
}
