// Problem: Rat in a Maze
// Platform: GeeksforGeeks
// Difficulty: Medium

// Approach:
// Use backtracking to explore all possible paths from (0,0) to (n-1,n-1).
// We move in 4 directions: Down, Right, Up, Left.
// Mark the current cell as visited (0) to avoid revisiting.
// After exploring, backtrack by restoring the cell.

// Time Complexity: O(4^(n*n)) in worst case
// Space Complexity: O(n*n) (recursion stack + path storage)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<string> result;
    
    // Check if cell is within bounds
    bool isSafe(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    
    void solve(int i, int j, vector<vector<int>> &m, int n, string& temp) {
        
        // Invalid cell or blocked
        if (!isSafe(i, j, n) || m[i][j] == 0) {
            return;
        }

        // Destination reached
        if (i == n - 1 && j == n - 1) {
            result.push_back(temp);
            return;
        }
        
        // Mark as visited
        m[i][j] = 0;
        
        // Move Down
        temp.push_back('D');
        solve(i + 1, j, m, n, temp);
        temp.pop_back();
        
        // Move Right
        temp.push_back('R');
        solve(i, j + 1, m, n, temp);
        temp.pop_back();
        
        // Move Up
        temp.push_back('U');
        solve(i - 1, j, m, n, temp);
        temp.pop_back();
        
        // Move Left
        temp.push_back('L');
        solve(i, j - 1, m, n, temp);
        temp.pop_back();
        
        // Backtrack: unmark cell
        m[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        string temp = "";
        
        // If starting point is blocked
        if (m[0][0] == 0) return {};
        
        solve(0, 0, m, n, temp);
        
        return result;
    }
};

// Key Learning:
// Backtracking with marking visited cells prevents infinite loops.
// Always restore state after recursion.