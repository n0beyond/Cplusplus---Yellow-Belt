#include <iostream>
#include <string>
#include <deque>
#include <algorithm>


using namespace std;

int main() 
{
    int x, N;
    cin >> x >> N;
    
    deque<string> d;
    d.push_back(to_string(x));
    
    char prev_oper = '/';
    
    for (int i = 0; i < N; i++)
    {
        char _char;
        int value;
        cin >> _char >> value;
        
        if ((prev_oper == '-' || prev_oper == '+') 
            && (_char == '*' || _char == '/'))
        {
            d.push_front("(");
            d.push_back(")");
        }
        
        string __char;
        __char += _char;
        prev_oper = _char;
        d.push_back(" ");
        d.push_back(__char);
        d.push_back(" ");
        d.push_back(to_string(value));
    }
    
    for (auto i : d)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}