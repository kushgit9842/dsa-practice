// Problem: Longest Substring Without Repeating Characters
// Platform: LeetCode
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium

// Approach:
// Use sliding window with two pointers (left and right).
// Maintain a set to store unique characters in the current window.
// If a duplicate character is found, shrink the window from the left
// until the duplicate is removed.
// Track the maximum window size during the process.

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++) {
            
            // If duplicate found, shrink window from left
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            // Add current character to set
            charSet.insert(s[right]);

            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;        
    }
};

// Key Learning:
// Sliding window + hash set helps maintain unique characters efficiently.