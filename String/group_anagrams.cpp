// Problem: Group Anagrams
// Platform: LeetCode
// Link: https://leetcode.com/problems/group-anagrams/
// Difficulty: Medium

// Approach:
// Use hashmap where key represents character frequency.
// For each string:
//   - Count frequency of each character (26 letters)
//   - Build a unique key using counts
//   - Store string in hashmap under that key
// Finally, return all grouped values.

// Time Complexity: O(n * k)
// n = number of strings, k = length of each string
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> ans;

        for (string& s : strs) {

            array<int, 26> count = {0};

            // Count frequency of each character
            for (char c : s) {
                count[c - 'a']++;
            }

            // Build key from frequency array
            string key;
            for (int num : count) {
                key += to_string(num) + "#";
            }

            ans[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& entry : ans) {
            result.push_back(move(entry.second));
        }

        return result;
    }
};

// Key Learning:
// Frequency-based hashing avoids sorting and gives efficient grouping of anagrams.