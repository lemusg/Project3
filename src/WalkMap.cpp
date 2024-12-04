//Gabriel Lemus
#include <fstream>
#include "WalkMap.h"
#include <iomanip>
#include <random>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

WalkMap::WalkMap(int mapSize, int numConnections){
    //generate random distributions for which nodes connected to and how many nodes to connect
    mt19937 rng(time(nullptr));
    uniform_int_distribution<int> conn(0, mapSize);
    uniform_int_distribution<int> numConn(1, numConnections);

    //create mapSize nodes with 0-numConnections connections
    for (int i = 0; i < mapSize; i++) {
        int size = connections[i].size();
        //numConn(rng) - connections[i].size() so nodes don't exceed numConnections connections
        for (int j = 0; j < numConn(rng) - size; j++) {
            //generate node to connect to
            int r = conn(rng);
            //prevent node from connecting to itself or a node with numConnections connections
            while (r == i || connections[r].size() == numConnections)
                r = conn(rng);
            //insert connection between node i and node r
            connections[i].push_back(r);
            connections[r].push_back(i);
        }
    }
    cout << "Map Generated" << endl;
}


//Santiago Tovar
void WalkMap::generateDotFile(const std::string& filename,
                              const set<int>& bfsVisitedNodes,
                              const set<pair<int, int>>& bfsVisitedEdges,
                              const set<int>& dfsVisitedNodes,
                              const set<pair<int, int>>& dfsVisitedEdges) {
    std::ofstream outFile(filename);
    outFile << "graph G {\n";  // Use "graph" for undirected graph

    // Write nodes
    for (const auto& node : connections) {
        if (bfsVisitedNodes.find(node.first) != bfsVisitedNodes.end()) {
            outFile << "  " << node.first << " [color=blue, style=filled];\n";  // BFS node: Blue
        } else if (dfsVisitedNodes.find(node.first) != dfsVisitedNodes.end()) {
            outFile << "  " << node.first << " [color=green, style=filled];\n";  // DFS node: Green
        } else {
            outFile << "  " << node.first << ";\n";  // Default node (unvisited)
        }
    }

    // Write edges
    set<pair<int, int>> addedEdges;  // To keep track of edges already added (undirected)

    for (const auto& node : connections) {
        for (const auto& neighbor : node.second) {
            // Create an edge in a consistent order (sorted by node ID)
            pair<int, int> edge = node.first < neighbor ? make_pair(node.first, neighbor) : make_pair(neighbor, node.first);

            if (addedEdges.find(edge) == addedEdges.end()) {  // Only add the edge once
                addedEdges.insert(edge);
                outFile << "  " << edge.first << " -- " << edge.second << ";\n";  // Regular edge (unvisited)
            }
        }
    }

    outFile << "}\n";
    outFile.close();
}
