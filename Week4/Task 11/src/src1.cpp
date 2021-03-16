#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() 
{
    int x, N;
    cin >> x >> N;
    string answer = to_string(x);
    for (int i = 0; i < N; i++)
    {
        string _char, value;
        cin >> _char >> value;
        answer.insert(0, "(");
        answer.push_back(')');
        answer += " " + _char + " " + value;
    }
    cout << answer << endl;
    return 0;
}