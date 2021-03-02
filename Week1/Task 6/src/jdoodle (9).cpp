#include <iostream>
#include <vector>
#include <map>


using namespace std;

template <class T> vector<T> Sqr(const vector<T>& a);
template <class First, class Second> pair<First, Second> Sqr(const pair<First, Second>& a);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& a);
template <class T> T Sqr(T a);

template <class First, class Second>
pair<First, Second> Sqr(const pair<First, Second>& a)
{
    auto i = a;
	i.first = Sqr(i.first);
	i.second = Sqr(i.second);
	return i;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& a)
{
    auto m = a;
	for (auto& [key, value] : m)
	{
		value = Sqr(value);
	}
	return m;
}

template <class T>
vector<T> Sqr(const vector<T>& a)
{
    auto k = a;
	for (auto& i : k)
	{
		i = Sqr(i);
	}
	return k;
}

template <class T>
T Sqr(T a)
{
    return a*a;
}

int main()
{
	// Пример вызова функции
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {{4, {2, 2}}, {7, {4, 3}}};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
