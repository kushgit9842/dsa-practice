// Problem: Longest Consecutive Sequence
// Platform: LeetCode
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty: Medium

// Approach:
// Insert all elements into a set for fast lookup.
// For each number, check if it is the start of a sequence
// (i.e., n-1 is not present).
// Then count the length of the sequence by checking n+1, n+2, etc.
// Track the maximum length.

// Time Complexity: O(n log n) (due to set)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (size(nums) == 0) return 0;

        set<int> st(nums.begin(), nums.end());

        int l = 0;

        for (int n : st) {

            // Check if it's the start of a sequence
            if (st.find(n - 1) == st.end()) {

                int currEl = n;
                int m = 1;

                // Count consecutive elements
                while (st.find(currEl + 1) != st.end()) {
                    currEl++;
                    m++;
                }

                l = max(l, m);
            }
        }

        return l;
    }
};

// Key Learning:
// Only start counting from sequence beginnings to avoid redundant work.