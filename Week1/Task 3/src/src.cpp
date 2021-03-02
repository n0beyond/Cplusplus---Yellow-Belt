#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<uint64_t> blocks;
    int n, r;
    cin >> n >> r;
    while(n-- != 0)
    {
        uint64_t w, h, d;
        cin >> w >> h >> d;
        blocks.push_back(w*h*d*r);
    }
    uint64_t sum = 0;
    for(auto c : blocks)
    {
        sum += c;
    }
    cout << sum <<endl;
    return 0;
}