// Problem: Word Break II
// Platform: LeetCode
// Link: https://leetcode.com/problems/word-break-ii/
// Difficulty: Hard

// Approach:
// Use backtracking to generate all possible sentences.
// At each index, try forming words using substrings.
// If the substring exists in dictionary, add it to current sentence
// and recursively process the remaining string.
// Backtrack after each recursive call to explore all possibilities.

// Time Complexity: Exponential (due to multiple partitions)
// Space Complexity: O(n) (recursion stack)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;
    unordered_set<string> dict;

    void solve(int i, string& currSentence, string &s) {

        // Base case: reached end of string
        if (i >= s.length()) {
            result.push_back(currSentence);
            return;
        }

        for (int j = i; j < s.length(); j++) {

            string tempWord = s.substr(i, j - i + 1);

            // Check if substring exists in dictionary
            if (dict.find(tempWord) != dict.end()) {

                string origSentence = currSentence;

                // Add space if needed
                if (!currSentence.empty())
                    currSentence += " ";
                
                currSentence += tempWord;

                // Recurse for remaining string
                solve(j + 1, currSentence, s);

                // Backtrack
                currSentence = origSentence;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        // Store dictionary words in set for fast lookup
        for (string &word : wordDict) {
            dict.insert(word);
        }

        string currSentence = "";

        solve(0, currSentence, s);

        return result;
    }
};

// Key Learning:
// Backtracking with dictionary lookup generates all valid sentences.
// This is a partitioning problem similar to palindrome partitioning.
