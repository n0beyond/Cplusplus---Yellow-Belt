#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q)
{
    string command;
    is >> command;
    if (command == "NEW_BUS")
    {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stops_count = 0;
        is >> stops_count;
        q.stops.resize(stops_count);
        for (auto& stop : q.stops)
        {
            is >> stop;
        }
    }
    if (command == "BUSES_FOR_STOP")
    {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    if (command == "STOPS_FOR_BUS")
    {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    if (command == "ALL_BUSES")
    {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse 
{
    vector<string> busesforstop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
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

struct StopsForBusResponse 
{
    bool flag = false;
    string bus;
    vector<string> buses, stops;
    map<string, vector<string>> stopnb;
};

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

struct AllBusesResponse 
{
    map<string, vector<string>> busesns;
};

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

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) 
    {
        buses.push_back(bus);
        busesns[bus] = stops;
        for (auto& stop : stops)
        {
            stopsnb[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const 
    {
        BusesForStopResponse q;
        if (stopsnb.count(stop) != 0u)
        {
            q.busesforstop = stopsnb.at(stop);
        }
        return q;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const 
    {
        StopsForBusResponse q;
        q.bus = bus;
        if (busesns.count(bus) != 0u)
        {
            q.flag = true;
            q.stops = busesns.at(bus);
        }
        q.buses = buses;
        q.stopnb = stopsnb;
        return q;
    }

    AllBusesResponse GetAllBuses() const 
    {
        AllBusesResponse q;
        q.busesns = busesns;
        return q;
    }
private:
    vector<string> buses;
    map<string, vector<string>> busesns, stopsnb;
};

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}