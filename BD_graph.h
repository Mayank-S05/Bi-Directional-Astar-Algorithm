#pragma once

#include <bits/stdc++.h>
using namespace std;

typedef pair<long, float> destWeight;
typedef set<destWeight> adjList;

struct Edge
{
    long src, dest;
    float weight;
};

class graph
{
  public:
    int V, E;
    unordered_map<long, adjList> myvec;

    vector< pair<long,float> > potentiala;
    vector< pair<long,float> > potentialb;
    vector<float> closeda;
    vector<float> closedb;
    vector<Edge> edgeList;

    vector< vector<float> > adjMatrix;

    graph();
    //void bd_dijkstra(long s,long d);
    int BD_a_star(long s , long d);
   // void dijkstra(long s,long d);
    void clr();
    void addEdge(long src, long dest, float weight);
    void dec_pot();
};
