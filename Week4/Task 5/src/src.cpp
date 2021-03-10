#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    sort(v.rbegin(), v.rend());
    do
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    } while (prev_permutation(v.begin(), v.end()));
    return 0;
}