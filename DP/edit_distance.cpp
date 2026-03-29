// Problem: Edit Distance
// Platform: LeetCode
// Link: https://leetcode.com/problems/edit-distance/
// Difficulty: Hard

// Approach:
// Use recursion with memoization (top-down DP).
// At each position (i, j), we compare characters of both strings.
// If characters match → move both pointers forward.
// Else we have three operations:
// 1. Insert
// 2. Delete
// 3. Replace
// Take minimum of all operations.

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[501][501]; // DP table
    int m, n;

    int solve(string& s1, string& s2, int i, int j) {

        // Base cases
        if (i == m)
            return n - j; // insert remaining characters of s2

        else if (j == n)
            return m - i; // delete remaining characters of s1

        // Return memoized result
        if (t[i][j] != -1)
            return t[i][j];
        
        // If characters match → no operation needed
        if (s1[i] == s2[j])
            return t[i][j] = solve(s1, s2, i + 1, j + 1);

        else {
            // Insert operation
            int insertC  = 1 + solve(s1, s2, i, j + 1);

            // Delete operation
            int deleteC  = 1 + solve(s1, s2, i + 1, j);

            // Replace operation
            int replaceC = 1 + solve(s1, s2, i + 1, j + 1);
            
            // Take minimum of all operations
            return t[i][j] = min({insertC, deleteC, replaceC});
        }
    }
    
    int minDistance(string s1, string s2) {
        m = s1.length();
        n = s2.length();

        memset(t, -1, sizeof(t)); // initialize DP table

        return solve(s1, s2, 0, 0);
    }
};

// Key Learning:
// Edit Distance is a classic DP problem involving 3 operations: insert, delete, replace.