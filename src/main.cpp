#include "WalkMap.h"
#include "BFS.h"
#include "DFS.h"
#include <iostream>

using namespace std;

int main() {
    int mapSize, numConnections;
    cout << "Enter a map size: ";
    cin >> mapSize;
    cout << "Enter the number of connections: ";
    cin >> numConnections;

    // Create the graph
    WalkMap walkMap(mapSize, numConnections);

    int src, dest;
    cout << "Enter the source node: ";
    cin >> src;
    cout << "Enter the destination node: ";
    cin >> dest;

    // Run BFS and DFS on the same graph
    cout << "Running BFS..." << endl;
    BFS::bfs(walkMap, src, dest);  // BFS Traversal

    cout << "Running DFS..." << endl;
    DFS::dfs(walkMap, src, dest);  // DFS Traversal

    return 0;
}

