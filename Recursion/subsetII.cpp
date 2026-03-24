// Problem: Subsets II
// Platform: LeetCode
// Link: https://leetcode.com/problems/subsets-ii/
// Difficulty: Medium

// Approach:
// Use backtracking to generate all subsets.
// First sort the array so duplicates come together.
// While iterating, skip duplicate elements at the same recursion level.

// Time Complexity: O(2^n)
// Space Complexity: O(n) (recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        result.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {

            // Skip duplicates at same recursion level
            if (i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            solve(nums, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;

        sort(nums.begin(), nums.end()); // required for duplicate handling
        solve(nums, 0, temp);

        return result;
    }
};

// Key Learning:
// Sorting + skipping duplicates ensures only unique subsets are generated.
// This pattern is widely used in backtracking problems with duplicates.