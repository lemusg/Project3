//Gabriel Lemus
#ifndef WalkMap_H
#define WalkMap_H

#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

class WalkMap {
public:
    map<int, vector<int>> connections;
    WalkMap(int mapSize, int numConnections);
};

#endif