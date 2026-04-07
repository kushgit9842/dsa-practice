// Problem: Next Permutation
// Platform: LeetCode
// Link: https://leetcode.com/problems/next-permutation/
// Difficulty: Medium

// Approach:
// 1. Traverse from right to find first decreasing element (pivot).
// 2. If no such element → reverse whole array (last permutation).
// 3. Find just greater element than pivot from right.
// 4. Swap them.
// 5. Reverse the suffix to get next smallest permutation.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int i = nums.size() - 1;

        // Step 1: find pivot
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        
        // Step 2: if no pivot → reverse entire array
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 3: find next greater element
        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i - 1]) {
            j--;
        }
        
        // Step 4: swap
        swap(nums[i - 1], nums[j]);

        // Step 5: reverse suffix
        reverse(nums.begin() + i, nums.end());
    }
};

// Key Learning:
// Next permutation finds the next lexicographically greater arrangement.