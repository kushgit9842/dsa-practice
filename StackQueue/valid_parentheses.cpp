// Problem: Valid Parentheses
// Platform: LeetCode
// Link: https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy

// Approach:
// Use a stack to keep track of opening brackets.
// Push opening brackets onto stack.
// For closing brackets:
//   - Check if stack is empty → invalid
//   - Check if top matches → pop
//   - Else → invalid
// At the end, stack should be empty.

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char i : s) {

            // Push opening brackets
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            }

            else {
                // If stack empty → no matching opening bracket
                if (st.empty()) return false;

                // Check matching pair
                if (st.top() == '(' && i == ')' ||
                    st.top() == '{' && i == '}' ||
                    st.top() == '[' && i == ']') {
                    
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Valid if stack is empty
        return st.size() == 0;
    }
};

// Key Learning:
// Stack helps track order and matching of brackets efficiently.