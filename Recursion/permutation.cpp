// Problem: Permutations
// Platform: LeetCode
// Link: https://leetcode.com/problems/permutations/
// Difficulty: Medium

// Approach:
// Use backtracking with swapping.
// Fix one element at current index and recursively generate permutations
// for the remaining elements.
// After recursion, swap back to restore original state (backtracking).

// Time Complexity: O(n!)
// Space Complexity: O(n) (recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    int n;
    
    void solve(int idx, vector<int>& nums) {

        // Base case: one permutation formed
        if (idx == n) {
            result.push_back(nums);
            return;
        }
        
        for (int i = idx; i < n; i++) {

            // Place element at current position
            swap(nums[i], nums[idx]);
            
            solve(idx + 1, nums);
            
            // Backtrack: restore original order
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};

// Key Learning:
// Swapping allows generating permutations in-place without extra space.
// This is a classic backtracking pattern.