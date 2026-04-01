// Problem: Longest Common Prefix
// Platform: LeetCode
// Link: https://leetcode.com/problems/longest-common-prefix/
// Difficulty: Easy

// Approach:
// Sort the array of strings.
// Compare only the first and last strings.
// The common prefix of these two will be the answer
// because they are the most different after sorting.

// Time Complexity: O(n log n + m)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {

        string ans = "";

        // Sort strings
        sort(v.begin(), v.end());

        int n = v.size();

        string first = v[0];
        string last = v[n - 1];

        // Compare characters of first and last string
        for (int i = 0; i < min(first.size(), last.size()); i++) {

            if (first[i] != last[i]) {
                return ans;
            }

            ans += first[i];
        }

        return ans;
    }
};

// Key Learning:
// After sorting, only first and last strings need comparison
// to find the common prefix.