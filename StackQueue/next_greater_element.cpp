// Problem: Next Greater Element I
// Platform: LeetCode
// Link: https://leetcode.com/problems/next-greater-element-i/
// Difficulty: Easy

// Approach:
// Use a monotonic decreasing stack to process nums2.
// For each element, pop smaller elements and assign their next greater.
// Store results in a hashmap.
// Then, for nums1, directly fetch answers from hashmap.

// Time Complexity: O(n + m)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> ng; // stores next greater element
        stack<int> st;              // monotonic decreasing stack

        for (int num : nums2) {

            // Pop smaller elements and assign their next greater
            while (!st.empty() && st.top() < num) {
                ng[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        vector<int> res;

        // Build result for nums1
        for (int num : nums1) {
            res.push_back(ng.count(num) ? ng[num] : -1);
        }

        return res;
    }
};

// Key Learning:
// Monotonic stack helps efficiently find next greater elements in linear time.