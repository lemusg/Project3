//Gabriel Lemus
#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

class WalkMap {
public:
    map<int, vector<int>> connections;
    WalkMap();
};