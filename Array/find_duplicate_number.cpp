// Problem: Find the Duplicate Number
// Platform: LeetCode
// Link: https://leetcode.com/problems/find-the-duplicate-number/
// Difficulty: Medium

// Approach:
// Use hashmap to count frequency.
// As soon as a number appears more than once, return it.

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int num : nums) {

            freq[num]++;

            if (freq[num] > 1) {
                return num;  // duplicate found
            }
        }

        return -1; // fallback (problem guarantees one duplicate)
    }
};

// Key Learning:
// Hashmap helps detect duplicates quickly but uses extra space.