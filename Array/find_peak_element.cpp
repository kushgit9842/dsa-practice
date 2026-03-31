// Problem: Find Peak Element
// Platform: LeetCode
// Link: https://leetcode.com/problems/find-peak-element/
// Difficulty: Medium

// Approach:
// Use binary search.
// Compare middle element with its next element.
// If nums[m] < nums[m+1], peak lies on right side.
// Else, peak lies on left side (including m).
// Continue until l == r.

// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int l = 0;
        int r = size(nums) - 1;
        
        while (l < r) {

            int m = l + (r - l) / 2;

            if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                r = m;
        }

        return l; // index of peak element
    }
};

// Key Learning:
// Binary search can be applied on unsorted arrays if a directional property exists.