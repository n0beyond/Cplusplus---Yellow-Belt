#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    vector<string> v;
    auto b = s.begin();
    while (b != s.end())
    {
        auto end = find(b, s.end(), ' ');
        string a(b, end);
        v.push_back(a);
        if(end != s.end())
        {
            b = next(end);
        }
        else
        {
            break;
        }
    }
    return v;
}