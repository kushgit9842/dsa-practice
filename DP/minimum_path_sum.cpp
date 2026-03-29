// Problem: Minimum Path Sum
// Platform: LeetCode
// Link: https://leetcode.com/problems/minimum-path-sum/
// Difficulty: Medium

// Approach:
// Use recursion with memoization (top-down DP).
// At each cell, we can move either right or down.
// Choose the path with minimum sum and store results in DP table.

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[201][201]; // DP table

    int MPS(vector<vector<int>>& grid, int i, int j, int m, int n) {

        // Base case: reached bottom-right cell
        if (i == m - 1 && j == n - 1)
            return t[i][j] = grid[i][j];

        // Return memoized result
        if (t[i][j] != -1)
            return t[i][j];

        // If last row → can only move right
        if (i == m - 1) {
            return t[i][j] = grid[i][j] + MPS(grid, i, j + 1, m, n);
        }

        // If last column → can only move down
        else if (j == n - 1) {
            return t[i][j] = grid[i][j] + MPS(grid, i + 1, j, m, n);
        }

        // Otherwise → choose minimum of right and down
        else {
            return t[i][j] = grid[i][j] + min(
                MPS(grid, i + 1, j, m, n),
                MPS(grid, i, j + 1, m, n)
            );
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memset(t, -1, sizeof(t)); // initialize DP table

        return MPS(grid, 0, 0, m, n);
    }
};

// Key Learning:
// Grid DP problems often involve moving in limited directions (right/down)
// and choosing optimal path using memoization.