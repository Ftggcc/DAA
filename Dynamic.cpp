#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {

    vector<int> dp(W + 1, 0); 



    for (int i = 0; i < n; i++) {

        

        for (int w = W; w >= weights[i]; w--) {

            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);

        }

    }

    

    return dp[W]; 

}



int main() {

    int n, W;

    cout << "Enter number of items and knapsack capacity: ";

    cin >> n >> W;



    vector<int> values(n), weights(n);

    cout << "Enter values and weights of items:\n";

    for (int i = 0; i < n; i++) {

        cin >> values[i] >> weights[i];

    }



    cout << "Maximum value in knapsack: " << knapsack(W, weights, values, n) << endl;

    return 0;

}

