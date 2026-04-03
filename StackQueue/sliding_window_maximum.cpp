// Problem: Sliding Window Maximum
// Platform: LeetCode
// Link: https://leetcode.com/problems/sliding-window-maximum/
// Difficulty: Hard

// Approach:
// Use a deque to maintain elements in decreasing order.
// For each element:
// 1. Remove smaller elements from back (they are useless).
// 2. Add current element.
// 3. Remove front element if it goes out of window.
// 4. Front of deque always gives maximum of current window.

// Time Complexity: O(n)
// Space Complexity: O(k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        deque<int> deque;

        for (int idx = 0; idx < nums.size(); idx++) {

            int num = nums[idx];

            // Maintain decreasing order
            while (!deque.empty() && deque.back() < num) {
                deque.pop_back();
            }

            deque.push_back(num);

            // Remove element going out of window
            if (idx >= k && nums[idx - k] == deque.front()) {
                deque.pop_front();
            }

            // Add result when window is valid
            if (idx >= k - 1) {
                res.push_back(deque.front());
            }
        }

        return res;
    }
};

// Key Learning:
// Monotonic deque helps maintain maximum in sliding window efficiently.
