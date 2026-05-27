// ============================
// Graph.h
// ============================

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

class Graph {

private:

    static const int MAX = 20000;

    vector<int> adj[MAX];

    bool visited[MAX];

    void DFSUtil(int node);

public:

    void addConnection(
        int id1,
        int id2
    );

    void showConnections(int id);

    bool areConnected(
        int id1,
        int id2
    );

    void BFS(int start);

    void DFS(int start);

    void removeStudent(int id);
};

#endif