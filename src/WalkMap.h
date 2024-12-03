//Gabriel Lemus
#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

class WalkMap {
private:
    map<int, vector<pair<int, double>>> connections;
public:
    WalkMap();
};