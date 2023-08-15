#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0-1 Knapsack problem using bottom-up dynamic programming (tabulation)
int knapsack(int n, int values[], int weights[], int capacity) {
    int dp[n + 1][capacity + 1];

    // Initializing the base case values
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    printf("Number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];
    printf("Item values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    printf("Item weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int capacity;
    printf("Knapsack weight capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(n, values, weights, capacity);
    printf("Maximum value: %d\n", result);

    return 0;
}
