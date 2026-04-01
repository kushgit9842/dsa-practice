// Problem: Reverse Words in a String
// Platform: LeetCode
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty: Medium

// Approach:
// 1. Reverse the entire string.
// 2. Traverse and extract each word.
// 3. Reverse each word individually.
// 4. Remove extra spaces and keep only single spaces between words.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        // Step 1: Reverse entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;

        while (i < n) {

            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i == n) break;

            // Copy word
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // Reverse current word
            reverse(s.begin() + left, s.begin() + right);

            // Add single space
            s[right++] = ' ';
            left = right;

            i++;
        }

        // Remove trailing space
        s.resize(right - 1);

        return s;
    }
};

// Key Learning:
// Reverse entire string first, then reverse each word to achieve final result.