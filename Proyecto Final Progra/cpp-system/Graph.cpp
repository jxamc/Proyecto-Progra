// ============================
// Graph.cpp
// ============================

#include "Graph.h"
#include "Queue.h"

void Graph::addConnection(
    int id1,
    int id2
) {

    if(id1 == id2) {

        cout
            << "No puede conectarse consigo mismo\n";

        return;
    }

    for(int x : adj[id1]) {

        if(x == id2) {

            cout
                << "Conexion duplicada\n";

            return;
        }
    }

    adj[id1].push_back(id2);

    adj[id2].push_back(id1);

    cout << "Conexion creada\n";
}

void Graph::showConnections(int id) {

    for(int x : adj[id]) {

        cout << x << endl;
    }
}

bool Graph::areConnected(
    int id1,
    int id2
) {

    for(int x : adj[id1]) {

        if(x == id2) {

            return true;
        }
    }

    return false;
}

void Graph::BFS(int start) {

    for(int i = 0; i < MAX; i++) {

        visited[i] = false;
    }

    Queue q;

    visited[start] = true;

    q.enqueue(start);

    while(!q.isEmpty()) {

        int current =
            q.dequeue();

        cout
            << current
            << " ";

        for(int neighbor :
            adj[current]) {

            if(!visited[neighbor]) {

                visited[neighbor] = true;

                q.enqueue(neighbor);
            }
        }
    }

    cout << endl;
}

void Graph::DFSUtil(int node) {

    visited[node] = true;

    cout << node << " ";

    for(int neighbor :
        adj[node]) {

        if(!visited[neighbor]) {

            DFSUtil(neighbor);
        }
    }
}

void Graph::DFS(int start) {

    for(int i = 0; i < MAX; i++) {

        visited[i] = false;
    }

    DFSUtil(start);

    cout << endl;
}

void Graph::removeStudent(int id) {

    adj[id].clear();

    for(int i = 0; i < MAX; i++) {

        for(auto it = adj[i].begin();
            it != adj[i].end();) {

            if(*it == id) {

                it =
                    adj[i].erase(it);
            }
            else {

                ++it;
            }
        }
    }
}