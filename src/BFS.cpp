//Gabriel Lemus

#include "BFS.h"
#include <set>
#include <queue>
#include <chrono>
#include <iostream>

using namespace std::chrono;

void BFS::bfs(WalkMap& map, int src, int dest) {
    auto start = high_resolution_clock::now();
    set<int> visited;
    queue<int> q;
    visited.insert(src);
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: map.connections[u]) {
            if (v == dest) {
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(end - start);
                cout << "Path Found! BFS Time Elapsed: " << duration.count();
                return;
            }
            if ((visited.find(v) == visited.end())) {
                    visited.insert(v);
                    q.push(v);
            }
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Path Not Found! BFS Time Elapsed: " << duration.count();
}
