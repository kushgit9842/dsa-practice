// Problem: Count and Say
// Platform: LeetCode
// Link: https://leetcode.com/problems/count-and-say/
// Difficulty: Medium

// Approach:
// Use recursion to generate previous sequence.
// Then iterate through it and "say" the count of consecutive digits.
// Build the result string accordingly.

// Time Complexity: O(2^n) (string grows exponentially)
// Space Complexity: O(n) recursion stack

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {

        // Base case
        if (n == 1)
            return "1";
        
        // Get previous sequence
        string say = countAndSay(n - 1);
        
        string result = "";
        
        // Count consecutive characters
        for (int i = 0; i < say.length(); i++) {
            
            int count = 1;
            char ch = say[i];
            
            while (i < say.length() - 1 && say[i] == say[i + 1]) {
                count++;
                i++;
            }
            
            result += to_string(count) + string(1, say[i]);
        }
        
        return result;
    }
};

// Key Learning:
// Build sequence by describing the previous term (run-length encoding style).