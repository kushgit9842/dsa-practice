// Problem: Valid Anagram
// Platform: LeetCode
// Link: https://leetcode.com/problems/valid-anagram/
// Difficulty: Easy

// Approach:
// Use hashmap to count frequency of characters.
// Increment count for string s and decrement for string t.
// If all counts become zero → anagram.

// Time Complexity: O(n)
// Space Complexity: O(1) (since at most 26 characters)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> mp;

        for (char i : s) {
            mp[i]++;
        }

        for (char i : t) {
            mp[i]--;
        }

        for (auto k : mp) {
            if (k.second != 0) return false;
        }

        return true;
    } 
};

// Key Learning:
// Frequency counting helps compare character distributions efficiently.