#include "query.h"
#include "responses.h"
#include "bus_manager.h"

using namespace std;

    void BusManager::AddBus(const string& bus, const vector<string>& stops)
    {
        buses.push_back(bus);
        busesns[bus] = stops;
        for (auto& stop : stops)
        {
            stopsnb[stop].push_back(bus);
        }
    }

    BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const
    {
        BusesForStopResponse q;
        if (stopsnb.count(stop) != 0u)
        {
            q.busesforstop = stopsnb.at(stop);
        }
        return q;
    }

    StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const
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
    
    AllBusesResponse BusManager::GetAllBuses() const
    {
        AllBusesResponse q;
        q.busesns = busesns;
        return q;
    }
