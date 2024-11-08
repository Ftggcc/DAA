#include <iostream>

#include <vector>

#include <climits>



using namespace std;



void bellmanFord(int V, int E, vector<vector<int>>& edges, int src) {

    vector<int> dist(V, INT_MAX);  

    dist[src] = 0;



    

    for (int i = 0; i < V - 1; i++) {

        for (int j = 0; j < E; j++) {

            int u = edges[j][0], v = edges[j][1], w = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;

            }

        }

    }



   

    for (int j = 0; j < E; j++) {

        int u = edges[j][0], v = edges[j][1], w = edges[j][2];

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {

            cout << "Graph contains negative weight cycle\n";

            return;

        }

    }



    

    cout << "Vertex Distance from Source (" << src << "):\n";

    for (int i = 0; i < V; i++) {

        if (dist[i] == INT_MAX) {

            cout << "INF ";

        } else {

            cout << dist[i] << " ";

        }

    }

    cout << endl;

}



int main() {

    int V, E;

    cout << "Enter number of vertices and edges: ";

    cin >> V >> E;



    vector<vector<int>> edges(E, vector<int>(3));  



    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {

        cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; 

    }



    int source;

    cout << "Enter source vertex: ";

    cin >> source;



    bellmanFord(V, E, edges, source);



    return 0;

}

