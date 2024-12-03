//Gabriel Lemus

#include "WalkMap.h"
#include "BFS.h"
#include <iostream>

using namespace std;

int main() {
    WalkMap walkMap;
    BFS::bfs(walkMap, 12505, 93960);
}