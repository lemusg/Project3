//Gabriel Lemus

#include "WalkMap.h"
#include <iomanip>
#include <random>
#include <iostream>

using namespace std;

WalkMap::WalkMap(){
    //generate random distributions for which nodes connected to, how many nodes connected to,
    // and distance between them
    mt19937 rng(time(nullptr));
    uniform_int_distribution<int> conn(0, 100000);
    uniform_int_distribution<int> numConn(1, 10);
    uniform_real_distribution<double> dist(0, 5);

    //create 100000 nodes with 1-10 connections with double distances between them from 0-5
    for (int i = 0; i < 100000; i++) {
        int size = connections[i].size();
        //numConn(rng) - connections[i].size() so nodes don't exceed 10 connections
        for (int j = 0; j < numConn(rng) - size; j++) {
            //generate node to connect to
            int r = conn(rng);
            //prevent node from connecting to itself or a node with 10 connections
            while (r == i || connections[r].size() == 10)
                r = conn(rng);
            //generate distance between nodes
            double d = dist(rng);
            //insert connection between node i and node r with distance d between them
            connections[i].emplace_back(r, d);
            connections[r].emplace_back(i, d);
        }
    }
    cout << "Map Generated" << endl;
}