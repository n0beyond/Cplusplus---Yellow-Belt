#include "query.h"

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