// Problem: Longest Increasing Subsequence (LIS)
// Platform: LeetCode
// Link: https://leetcode.com/problems/longest-increasing-subsequence/
// Difficulty: Medium

// Approach:
// Use recursion with memoization (top-down DP).
// At each index, we have two choices:
// 1. Take the current element (if it's greater than previous)
// 2. Skip the current element
// Use DP table to store results for (prev_idx, curr_idx) to avoid recomputation.

// Time Complexity: O(n^2)
// Space Complexity: O(n^2) (DP table + recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[2501][2501];

    int lis(vector<int>& nums, int prev_idx, int curr_idx) {

        // Base case: reached end of array
        if (curr_idx == n)
            return 0;

        // Check memoized result
        if (prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];

        int taken = 0;

        // Option 1: take current element if valid
        if (prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
            taken = 1 + lis(nums, curr_idx, curr_idx + 1);

        // Option 2: skip current element
        int not_taken = lis(nums, prev_idx, curr_idx + 1);

        // Store result only when prev_idx is valid
        if (prev_idx != -1)
            t[prev_idx][curr_idx] = max(taken, not_taken);

        return max(taken, not_taken);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t)); // initialize DP table
        n = nums.size();
        return lis(nums, -1, 0);
    }
};

// Key Learning:
// LIS can be solved using recursion + memoization by exploring take/not-take choices.