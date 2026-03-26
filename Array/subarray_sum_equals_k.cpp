// Problem: Subarray Sum Equals K
// Platform: LeetCode
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Medium

// Approach:
// Use prefix sum + hashmap.
// Store frequency of prefix sums.
// For each index, check if (current sum - k) exists in map.
// If yes, it means there exists a subarray with sum k.

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s = 0; // prefix sum
        int c = 0; // count of subarrays
        unordered_map<int, int> mp;

        for (int i = 0; i < size(nums); i++) {
            s += nums[i];

            int d = s - k;

            if (s == k) {
                c++;
            }

            if (mp.count(d)) {
                c += mp[d];
            }

            mp[s]++;
        }

        return c;
    }
};

// Key Learning:
// Prefix sum + hashmap helps reduce O(n^2) brute force to O(n).