#pragma once

#include "responses.h"

#include <vector>
#include <string>
#include <map>

using namespace std;

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;

    StopsForBusResponse GetStopsForBus(const string& bus) const;
    
    AllBusesResponse GetAllBuses() const;
private:
    vector<string> buses;
    map<string, vector<string>> busesns, stopsnb;
};