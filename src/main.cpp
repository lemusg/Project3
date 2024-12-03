//Gabriel Lemus

#include "WalkMap.h"
#include "BFS.h"
#include "DFS.h"

using namespace std;

int main() {
    WalkMap walkMap;
    BFS::bfs(walkMap, 12505, 93960);
    DFS::dfs(walkMap, 12505, 93960);
}