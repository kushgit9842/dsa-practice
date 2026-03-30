// Problem: Word Break
// Platform: LeetCode
// Link: https://leetcode.com/problems/word-break/
// Difficulty: Medium

// Approach:
// Use recursion with memoization (top-down DP).
// At each index, try all possible substrings starting from that index.
// If a substring exists in dictionary and remaining string can be solved,
// return true.
// Use DP array to store results for each index to avoid recomputation.

// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> st; // dictionary for fast lookup
    int t[301];               // DP array
    int n;
    
    bool solve(string &s, int idx) {
        
        // Base case: reached end of string
        if (idx == n) {
            return true;
        }

        // Optimization: check remaining substring directly
        if (st.find(s.substr(idx, n - idx)) != st.end()) {
            return true;
        }
        
        // Return memoized result
        if (t[idx] != -1)
            return t[idx];
        
        // Try all possible substring lengths
        for (int l = 1; l <= n; l++) {
            
            string temp = s.substr(idx, l);

            // If word exists and remaining part is valid
            if (st.find(temp) != st.end() && solve(s, idx + l))
                return t[idx] = true;
        }
        
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        memset(t, -1, sizeof(t)); // initialize DP
        
        // Insert words into set
        for (string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
};

// Key Learning:
// DP + recursion avoids recomputation of overlapping subproblems.