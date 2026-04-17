// ─────────────────────────────────────────
// Problem : Maximum Number of Non-Overlapping Substrings
// Difficulty: Hard
// Topic    : Greedy
// Tags     : Hash Table, String, Greedy, Sorting
// Date     : 2026-04-17
// ─────────────────────────────────────────
// Problem: Maximum Number of Non-Overlapping Substrings
// Platform: LeetCode
// Difficulty: Hard

// Approach:
// 1. Store first and last occurrence of each character
// 2. Try to form valid substring from each character
// 3. Expand interval if needed
// 4. Keep only valid intervals
// 5. Sort by end index and pick non-overlapping substrings

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, -1), last(26, -1);

        // Step 1: store first and last occurrence
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;

        // Step 2: try each character
        for (int i = 0; i < n; i++) {

            if (i != first[s[i] - 'a']) continue;

            int start = i;
            int end = last[s[i] - 'a'];

            bool valid = true;

            // Step 3: expand interval
            for (int j = start; j <= end; j++) {

                if (first[s[j] - 'a'] < start) {
                    valid = false;
                    break;
                }

                end = max(end, last[s[j] - 'a']);
            }

            if (valid) {
                intervals.push_back({start, end});
            }
        }

        // Step 4: sort by end index
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> result;
        int prevEnd = -1;

        // Step 5: pick non-overlapping
        for (auto &p : intervals) {
            if (p.first > prevEnd) {
                result.push_back(s.substr(p.first, p.second - p.first + 1));
                prevEnd = p.second;
            }
        }

        return result;
    }
};