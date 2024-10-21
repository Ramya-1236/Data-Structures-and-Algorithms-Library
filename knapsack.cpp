#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            // If the current item can be included
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w]; // Item not included
            }
        }
    }

    return dp[n][capacity]; // Return the maximum value that can be carried
}

// Utility function to display the results
void displayResult(int maxValue) {
    cout << "Maximum value in the knapsack: " << maxValue << endl;
}

int main() {
    vector<int> weights = {1, 2, 3};   // Weights of items
    vector<int> values = {10, 15, 40}; // Values of items
    int capacity = 6;                  // Maximum capacity of the knapsack
    int n = weights.size();            // Number of items

    int maxValue = knapsack(capacity, weights, values, n); // Solve knapsack problem

    displayResult(maxValue); // Display the result

    return 0; // End of program
}
