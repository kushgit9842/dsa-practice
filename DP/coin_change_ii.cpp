// Problem: Coin Change II
// Platform: LeetCode
// Link: https://leetcode.com/problems/coin-change-ii/
// Difficulty: Medium

// Approach:
// Use recursion with memoization (top-down DP).
// At each index, we have two choices:
// 1. Take the coin (stay at same index since unlimited supply)
// 2. Skip the coin (move to next index)
// Count total number of ways to form the amount.

// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[301][5001]; // DP table

    int solve(int i, vector<int>& coins, int amount) {

        // Base case: exact amount formed
        if (amount == 0)
            return t[i][amount] = 1;

        // No coins left or invalid amount
        if (i == n || amount < 0)
            return 0;

        // Return memoized result
        if (t[i][amount] != -1)
            return t[i][amount];

        // If coin is larger than remaining amount → skip
        if (coins[i] > amount)
            return t[i][amount] = solve(i + 1, coins, amount);

        // Option 1: take coin (stay at same index)
        int take = solve(i, coins, amount - coins[i]);

        // Option 2: skip coin
        int skip = solve(i + 1, coins, amount);

        return t[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();

        memset(t, -1, sizeof(t)); // initialize DP

        return solve(0, coins, amount);
    }
};

// Key Learning:
// This is an unbounded knapsack problem where we count combinations,
// not permutations.