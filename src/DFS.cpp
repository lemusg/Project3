#include "DFS.h"
#include "BFS.h"
#include "WalkMap.h"
#include <set>
#include <stack>
#include <chrono>
#include <iostream>

using namespace std;

void DFS::dfs(WalkMap& map, int src, int dest) {
    auto start = chrono::high_resolution_clock::now();
    set<int> visited;
    stack<int> s;
    visited.insert(src);
    s.push(src);

    set<int> dfsVisitedNodes;
    set<pair<int, int>> dfsVisitedEdges;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        dfsVisitedNodes.insert(u);

        // Update the DOT file with the current state (DFS coloring)
        map.generateDotFile("dfs_graph.dot", set<int>(), set<pair<int, int>>(), dfsVisitedNodes, dfsVisitedEdges);

        // Regenerate the graph with Graphviz
        system("dot -Tpng dfs_graph.dot -o dfs_graph.png");

        if (u == dest) {
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Path Found! DFS Time Elapsed: " << duration.count() << " ms\n";
            break;  // Stop DFS once the destination is found
        }

        for (auto v : map.connections[u]) {
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                s.push(v);
                dfsVisitedEdges.insert({u, v});
                dfsVisitedEdges.insert({v, u});  // Mark the edge as visited in DFS
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "DFS Time Elapsed: " << duration.count() << " ms\n";
}