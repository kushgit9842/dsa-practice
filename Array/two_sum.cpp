// Problem: Two Sum
// Platform: LeetCode
// Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy

// Approach:
// Use a hash map to store visited elements.
// For each element, check if (target - element) exists.

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> numMap;

        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];

            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }

            numMap[arr[i]] = i;
        }

        return {};
    }
};