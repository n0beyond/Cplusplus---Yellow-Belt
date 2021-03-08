#include "responses.h"

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r)
{
    if (r.busesforstop.size() == 0u)
    {
        os << "No stop";
        return os;
    }
    for (const auto& i : r.busesforstop)
    {
        os << i << " ";
    }
    return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r)
{
    if (!r.flag)
    {
        os << "No bus";
        return os;
    }
    auto x = r.stops.size();
    for (const auto& i : r.stops)
    {
        --x;
        os << "Stop " << i << ": ";
        if (r.stopnb.at(i).size() == 1u)
        {
            os << "no interchange";
        }
        else
        {
            for (const auto& c : r.stopnb.at(i))
            {
                if (c != r.bus)
                {
                    os << c << " ";
                }
            }
        }
        if (x)
        {
            os << endl;
        }
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r)
{
    if (r.busesns.size() == 0u)
    {
        os << "No buses";
        return os;
    }
    auto x = r.busesns.size();
    for (const auto& i : r.busesns)
    {
        --x;
        os << "Bus " << i.first << ": ";
        for (const auto& c : i.second)
        {
            os << c << " ";
        }
        if (x)
        {
            os << endl;
        }
    }
    return os;
}