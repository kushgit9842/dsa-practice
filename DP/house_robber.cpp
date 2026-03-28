// Problem: House Robber
// Platform: LeetCode
// Link: https://leetcode.com/problems/house-robber/
// Difficulty: Medium

// Approach:
// Use recursion with memoization (top-down DP).
// At each index, we have two choices:
// 1. Rob current house → move to i+2
// 2. Skip current house → move to i+1
// Store results in DP array to avoid recomputation.

// Time Complexity: O(n)
// Space Complexity: O(n) (DP array + recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[101]; // DP array

    int solve(vector<int>& nums, int i, int& n) {

        // Base case: beyond last house
        if (i >= n)
            return 0;

        // Return memoized result
        if (t[i] != -1)
            return t[i];
        
        // Option 1: rob current house
        int take = nums[i] + solve(nums, i + 2, n);

        // Option 2: skip current house
        int skip = solve(nums, i + 1, n);
        
        // Store and return maximum
        return t[i] = max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();

        memset(t, -1, sizeof(t)); // initialize DP array

        return solve(nums, 0, n);
    }
};

// Key Learning:
// This is a classic DP problem where we decide to take or skip each element.