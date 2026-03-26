// Problem: Palindrome Partitioning
// Platform: LeetCode
// Link: https://leetcode.com/problems/palindrome-partitioning/
// Difficulty: Medium

// Approach:
// Use backtracking to generate all possible partitions.
// At each index, try all possible substrings.
// If a substring is a palindrome, include it and recurse for remaining string.
// Backtrack after exploring each possibility.

// Time Complexity: O(2^n * n)
// Space Complexity: O(n) (recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    
    // Check if substring s[l...r] is palindrome
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void backtrack(string &s, int idx, vector<string> curr, vector<vector<string>> &result) {
        
        // Base case: reached end of string
        if (idx == n) {
            result.push_back(curr);
            return;
        }
        
        // Try all partitions starting from idx
        for (int i = idx; i < n; i++) {
            
            // Check if substring is palindrome
            if (isPalindrome(s, idx, i)) {
                
                curr.push_back(s.substr(idx, i - idx + 1));
                
                backtrack(s, i + 1, curr, result);
                
                curr.pop_back(); // backtrack
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        n = s.length();
        
        vector<vector<string>> result;
        vector<string> curr;
        
        backtrack(s, 0, curr, result);
        
        return result;
    }
};

// Key Learning:
// Backtracking + palindrome checking generates all valid partitions.
// This is a combination-style recursion with pruning.