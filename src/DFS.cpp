//Gabriel Lemus

#include "DFS.h"
#include <set>
#include <stack>
#include <chrono>
#include <iostream>

using namespace std::chrono;

void DFS::dfs(WalkMap& map, int src, int dest) {
    auto start = high_resolution_clock::now();
    set<int> visited;
    stack<int> s;
    visited.insert(src);
    s.push(src);
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        for(auto v: map.connections[u]) {
            if (v == dest) {
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - start);
                cout << "Path Found! DFS Time Elapsed: " << duration.count() << endl;
                return;
            }
            if ((visited.find(v) == visited.end())) {
                    visited.insert(v);
                    s.push(v);
            }
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Path Not Found! BFS Time Elapsed: " << duration.count() << endl;
}