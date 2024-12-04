//Gabriel Lemus

#include "BFS.h"
#include <set>
#include <queue>
#include <chrono>
#include <iostream>

using namespace std;

void BFS::bfs(WalkMap& map, int src, int dest) {
    auto start = chrono::high_resolution_clock::now();
    set<int> visited;
    queue<int> q;
    visited.insert(src);
    q.push(src);
    set<int> bfsVisitedNodes;
    set<pair<int, int>> bfsVisitedEdges;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bfsVisitedNodes.insert(u);

        // Update the DOT file with the current state (BFS coloring)
        map.generateDotFile("bfs_graph.dot", bfsVisitedNodes, bfsVisitedEdges, set<int>(), set<pair<int, int>>());

        // Regenerate the graph with Graphviz (you can run this as a system call)
        system("dot -Tpng bfs_graph.dot -o bfs_graph.png");

        if (u == dest) {
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Path Found! BFS Time Elapsed: " << duration.count() << " ms\n";
            break;  // Stop BFS once the destination is found
        }

        for (auto v : map.connections[u]) {
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                q.push(v);
                bfsVisitedEdges.insert({u, v});
                bfsVisitedEdges.insert({v, u});  // Mark the edge as visited in BFS
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "BFS Time Elapsed: " << duration.count() << " ms\n";
}