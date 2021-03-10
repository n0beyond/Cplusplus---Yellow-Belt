#include <algorithm>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements)
{
    sort(elements.begin(), elements.end());
    auto last = unique(elements.begin(), elements.end());
    elements.erase(last, elements.end());
}