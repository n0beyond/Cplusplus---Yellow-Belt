#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct BusesForStopResponse 
{
    vector<string> busesforstop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse 
{
    bool flag = false;
    string bus;
    vector<string> buses, stops;
    map<string, vector<string>> stopnb;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse 
{
    map<string, vector<string>> busesns;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);