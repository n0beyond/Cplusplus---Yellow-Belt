#include <iostream>
#include <vector>
#include <map>


using namespace std;

template <typename Key, typename Value, class T>
Value& GetRefStrict(map<Key, Value>& m, T k)
{
	if (m.count(k) == 0u)
	{
		throw runtime_error("");
	}
	return m.at(k);
}


int main()
{
	map<int, int> m = { {0, 0} };
	int& item = GetRefStrict(m, 0);
	item = 28;
	cout << m[0] << endl; // выведет 28
}