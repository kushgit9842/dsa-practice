// Problem: Find the Index of the First Occurrence in a String (strStr)
// Platform: LeetCode
// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Difficulty: Easy

// Approach:
// Traverse the haystack string.
// At each index, extract a substring of length equal to needle.
// Compare it with needle.
// If equal → return index.
// If no match found → return -1.

// Time Complexity: O(n * m)
// Space Complexity: O(m)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (haystack.length() < needle.length()) {
            return -1;
        }
        
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {

            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        
        return -1;
    }
};

// Key Learning:
// Brute-force substring comparison works but can be optimized using KMP algorithm.