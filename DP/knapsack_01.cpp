// Problem: 0/1 Knapsack
// Platform: GeeksforGeeks
// Difficulty: Medium

// Approach:
// Use recursion with memoization (top-down DP).
// At each index, we have two choices:
// 1. Take the item (if weight allows)
// 2. Skip the item
// Store results in DP table to avoid recomputation.

// Time Complexity: O(n * W)
// Space Complexity: O(n * W)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n;
    int t[1001][1001]; // DP table

    int solve(int i, int W, vector<int>& val, vector<int>& wt) {

        // Base case: no items left or capacity is 0
        if (i >= n || W == 0)
            return 0;

        // Return memoized result
        if (t[i][W] != -1) {
            return t[i][W];
        }

        int take = 0;
        int skip = 0;

        // Option 1: take item if weight allows
        if (wt[i] <= W) {
            take = val[i] + solve(i + 1, W - wt[i], val, wt);
        }

        // Option 2: skip item
        skip = solve(i + 1, W, val, wt);

        // Store and return maximum value
        return t[i][W] = max(take, skip);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        n = val.size();

        memset(t, -1, sizeof(t)); // initialize DP table

        return solve(0, W, val, wt);
    }
};

// Key Learning:
// 0/1 Knapsack is a classic "take or skip" DP problem with two states: index and capacity.