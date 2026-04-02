// Problem: Longest Common Subsequence
// Platform: LeetCode
// Link: https://leetcode.com/problems/longest-common-subsequence/
// Difficulty: Medium

// Approach:
// Use recursion with memoization (top-down DP).
// If characters match → include it and move both pointers.
// Else → take max of skipping one character from either string.
// Store results in DP table to avoid recomputation.

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[1001][1001]; // DP table

    int LCS(string& s1, string& s2, int m, int n) {

        // Base case: if any string is empty
        if (m == 0 || n == 0)
            return t[m][n] = 0;

        // Return memoized result
        if (t[m][n] != -1)
            return t[m][n];

        // If characters match
        if (s1[m - 1] == s2[n - 1])
            return t[m][n] = 1 + LCS(s1, s2, m - 1, n - 1);

        // Else take max of two possibilities
        return t[m][n] = max(
            LCS(s1, s2, m, n - 1),
            LCS(s1, s2, m - 1, n)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();
        int n = text2.length();

        memset(t, -1, sizeof(t)); // initialize DP table

        return LCS(text1, text2, m, n);
    }
};

// Key Learning:
// LCS is a classic DP problem where we compare two strings
// and build solution using optimal substructure.