// Problem: Subsets
// Platform: LeetCode
// Link: https://leetcode.com/problems/subsets/
// Difficulty: Medium

// Approach:
// Use recursion with include/exclude strategy.
// At each index, we have two choices:
// 1. Include the current element
// 2. Exclude the current element
// This generates all possible subsets.

// Time Complexity: O(2^n)
// Space Complexity: O(n) (recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        if (idx >= nums.size()) {
            result.push_back(temp); // store current subset
            return;
        }

        // Include current element
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);

        // Backtrack
        temp.pop_back();

        // Exclude current element
        solve(nums, idx + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        solve(nums, 0, temp);

        return result;
    }
};

// Key Learning:
// Include/Exclude recursion pattern generates all subsets (power set).