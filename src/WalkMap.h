//Gabriel Lemus
#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

class WalkMap {
private:
    //Think about what member variables you need to initialize
    map<int, vector<pair<int, double>>> connections;
public:
    //Think about what helper functions you will need in the algorithm
    WalkMap();
    void printMapNode(int node);
    void findErrors();
};