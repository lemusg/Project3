//Gabriel Lemus

#include "WalkMap.h"
#include <iomanip>
#include <random>
#include <iostream>

using namespace std;

WalkMap::WalkMap(){
    //generate random distributions for which nodes connected to and how many nodes to connect
    mt19937 rng(time(nullptr));
    uniform_int_distribution<int> conn(0, 100000);
    uniform_int_distribution<int> numConn(0, 10);

    //create 100000 nodes with 0-10 connections
    for (int i = 0; i < 100000; i++) {
        int size = connections[i].size();
        //numConn(rng) - connections[i].size() so nodes don't exceed 10 connections
        for (int j = 0; j < numConn(rng) - size; j++) {
            //generate node to connect to
            int r = conn(rng);
            //prevent node from connecting to itself or a node with 10 connections
            while (r == i || connections[r].size() == 10)
                r = conn(rng);
            //insert connection between node i and node r
            connections[i].push_back(r);
            connections[r].push_back(i);
        }
    }
    cout << "Map Generated" << endl;
}