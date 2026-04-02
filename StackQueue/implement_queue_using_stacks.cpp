// Problem: Implement Queue using Stacks
// Platform: LeetCode
// Link: https://leetcode.com/problems/implement-queue-using-stacks/
// Difficulty: Easy

// Approach:
// Use two stacks:
// 1. input stack → for push operations
// 2. output stack → for pop/peek operations
// When output is empty, transfer all elements from input to output.
// This reverses order and simulates queue behavior (FIFO).

// Time Complexity:
// Push: O(1)
// Pop: Amortized O(1)
// Peek: Amortized O(1)
// Empty: O(1)

// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;    

public:
    MyQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        peek(); // ensure output has elements
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        // Transfer elements only when needed
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

// Key Learning:
// Lazy transfer (only when needed) ensures amortized O(1) operations.