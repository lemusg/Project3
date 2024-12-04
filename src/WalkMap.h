//Gabriel Lemus
#ifndef WalkMap_H
#define WalkMap_H

#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class WalkMap {
public:
    map<int, vector<int>> connections;
    WalkMap(int mapSize, int numConnections);

    void
    generateDotFile(const string &filename, const set<int> &bfsVisitedNodes, const set<pair<int, int>> &bfsVisitedEdges,
                    const set<int> &dfsVisitedNodes, const set<pair<int, int>> &dfsVisitedEdges);
};

#endif