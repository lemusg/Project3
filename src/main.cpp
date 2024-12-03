//Gabriel Lemus

#include "WalkMap.h"
#include "BFS.h"
#include "DFS.h"
#include <iostream>

using namespace std;

int main() {
    int mapSize, numConnections;
    cin >> mapSize;
    cin >> numConnections;
    WalkMap walkMap(mapSize, numConnections);
    BFS::bfs(walkMap, 10000, 20000);
    DFS::dfs(walkMap, 10000, 20000);
}