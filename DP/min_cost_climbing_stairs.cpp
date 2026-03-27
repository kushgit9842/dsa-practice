// Problem: Min Cost Climbing Stairs
// Platform: LeetCode
// Link: https://leetcode.com/problems/min-cost-climbing-stairs/
// Difficulty: Easy

// Approach:
// Use recursion with memoization (top-down DP).
// At each index, we have two choices:
// 1. Move one step ahead
// 2. Move two steps ahead
// Store results in DP array to avoid recomputation.

// Time Complexity: O(n)
// Space Complexity: O(n) (recursion stack + DP array)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[1001]; // DP array for memoization

    int solve(vector<int>& cost, int idx) {
        
        // Base case: reached beyond last step
        if (idx >= cost.size())
            return 0;

        // Return already computed result
        if (t[idx] != -1)
            return t[idx];
			
        int move_one = cost[idx] + solve(cost, idx + 1);
        int move_two = cost[idx] + solve(cost, idx + 2);
        
        // Store and return minimum cost
        return t[idx] = min(move_one, move_two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        memset(t, -1, sizeof(t)); // initialize DP array

        // We can start from index 0 or 1
        return min(solve(cost, 0), solve(cost, 1));
    }
};

// Key Learning:
// Memoization helps avoid recomputation and reduces time complexity from exponential to linear.