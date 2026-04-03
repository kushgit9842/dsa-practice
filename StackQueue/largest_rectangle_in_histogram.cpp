// Problem: Largest Rectangle in Histogram
// Platform: LeetCode
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Difficulty: Hard

// Approach:
// Use a monotonic increasing stack to store indices.
// For each bar:
//   - Pop elements while current height is smaller
//   - Calculate area using popped height as smallest bar
//   - Width = current index - previous smaller index - 1
// After traversal, process remaining elements in stack.

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> stack;
        stack.push(-1); // sentinel to simplify width calculation

        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {

            // Maintain increasing stack
            while (stack.top() != -1 && heights[i] <= heights[stack.top()]) {

                int height = heights[stack.top()];
                stack.pop();

                int width = i - stack.top() - 1;

                max_area = max(max_area, height * width);
            }

            stack.push(i);
        }

        // Process remaining elements
        while (stack.top() != -1) {

            int height = heights[stack.top()];
            stack.pop();

            int width = heights.size() - stack.top() - 1;

            max_area = max(max_area, height * width);
        }

        return max_area;
    }
};

// Key Learning:
// Monotonic stack helps find nearest smaller elements efficiently,
// enabling O(n) solution for histogram problems.