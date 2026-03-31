// Problem: Merge Sorted Array
// Platform: LeetCode
// Link: https://leetcode.com/problems/merge-sorted-array/
// Difficulty: Easy

// Approach:
// Use three pointers starting from the end:
// i → last element of nums1 (valid part)
// j → last element of nums2
// k → last position of nums1 (total size)
// Compare elements from back and place the larger one at position k.
// Continue until all elements of nums2 are merged.

// Time Complexity: O(m + n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;         // pointer for nums1
        int j = n - 1;         // pointer for nums2
        int k = m + n - 1;     // pointer for merged array
        
        while (j >= 0) {

            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

// Key Learning:
// Filling from the back avoids overwriting elements in nums1.