#include <iostream>

#include <vector>

#include <climits>

#include <algorithm>



using namespace std;





#define N 4





int minCost(int graph[N][N], vector<int>& path) {

    int cost = 0;

    for (int i = 0; i < path.size() - 1; ++i) {

        cost += graph[path[i]][path[i + 1]];

    }

    cost += graph[path[path.size() - 1]][path[0]]; // Return to the starting city

    return cost;

}





void printMatrix(int graph[N][N]) {

    cout << "Cost matrix:\n";

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            cout << graph[i][j] << " ";

        }

        cout << endl;

    }

}





int branchAndBound(int graph[N][N]) {

    vector<int> path;

    vector<bool> visited(N, false);



    int min_path_cost = INT_MAX;

    vector<int> best_path;



    

    function<void(int, int)> dfs = [&](int city, int path_cost) {

        

        if (path.size() == N) {

            int total_cost = path_cost + graph[city][path[0]]; // Close the cycle

            if (total_cost < min_path_cost) {

                min_path_cost = total_cost;

                best_path = path;

                best_path.push_back(path[0]); // Add starting city at the end to complete the cycle

            }

            return;

        }



        

        for (int next_city = 0; next_city < N; ++next_city) {

            if (!visited[next_city] && graph[city][next_city] != 0) {

                visited[next_city] = true;

                path.push_back(next_city);

                dfs(next_city, path_cost + graph[city][next_city]);

                path.pop_back();

                visited[next_city] = false;

            }

        }

    };



   

    visited[0] = true;

    path.push_back(0);

    dfs(0, 0);



    

    cout << "Optimal path: ";

    for (int i : best_path) {

        cout << i << " ";

    }

    cout << endl;

    return min_path_cost;

}



int main() {

    

    int graph[N][N] = {

        {0, 10, 15, 20},

        {10, 0, 35, 25},

        {15, 35, 0, 30},

        {20, 25, 30, 0}

    };



    printMatrix(graph);



    int min_cost = branchAndBound(graph);

    cout << "Minimum cost of the tour: " << min_cost << endl;



    return 0;

}

