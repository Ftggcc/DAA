#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



struct Item {

    int value;

    int weight;

    double value_per_weight;

};





bool compare(Item a, Item b) {

    return a.value_per_weight > b.value_per_weight;

}



int main() {

    int n, W;

    cout << "Enter the number of items: ";

    cin >> n;

    cout << "Enter the knapsack capacity: ";

    cin >> W;



    vector<Item> items(n);



    

    cout << "Enter item values and weights (value weight):\n";

    for (int i = 0; i < n; i++) {

        cin >> items[i].value >> items[i].weight;

        items[i].value_per_weight = (double)items[i].value / items[i].weight;  

    }



    

    sort(items.begin(), items.end(), compare);



    int totalValue = 0;

    int totalWeight = 0;



    

    for (auto& item : items) {

        if (totalWeight + item.weight <= W) {

            totalWeight += item.weight;

            totalValue += item.value;

        }

    }



    cout << "Maximum value in Knapsack = " << totalValue << endl;



    return 0;

}

