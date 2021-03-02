#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> days;
    int n;
    cin >> n;
    while(n-- != 0)
    {
        int tem;
        cin >> tem;
        days.push_back(tem);
    }
    int64_t sum;
    for(size_t k = 0; k < days.size(); k++)
    {
        int i = k;
        sum += days[k];
    }
    int64_t avg = sum / static_cast<int>(days.size());
    static_cast<int>(avg);
    int num_of_days = 0;
    vector<int> avgdays;
    for(size_t k = 0; k < days.size(); k++)
    {
        int i = k;
        if(avg < days[k])
        {
            num_of_days++;
            avgdays.push_back(k);
        }
    }
    cout << num_of_days << endl;
    for(auto c : avgdays)
    {
        cout << c << " ";
    }
    return 0;
}