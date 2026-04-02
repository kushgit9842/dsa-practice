// Problem: Implement Stack using Queues
// Platform: LeetCode
// Link: https://leetcode.com/problems/implement-stack-using-queues/
// Difficulty: Easy

// Approach:
// Use two queues to simulate stack behavior (LIFO).
// Push → simply push into q1.
// Pop → move all elements except last to q2, remove last element.
// Top → similar to pop, but push the last element back.
// Swap q1 and q2 after each operation.

// Time Complexity:
// Push: O(1)
// Pop: O(n)
// Top: O(n)
// Empty: O(1)

// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        // Move all except last element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int poppedVal = q1.front();
        q1.pop();

        // Swap queues
        std::swap(q1, q2);

        return poppedVal;
    }

    int top() {
        // Move all except last element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topVal = q1.front();

        // Put it back into q2
        q2.push(q1.front());
        q1.pop();

        // Swap queues
        std::swap(q1, q2);

        return topVal;
    }

    bool empty() {
        return q1.empty();
    }
};

// Key Learning:
// Stack (LIFO) can be simulated using queues (FIFO) by rearranging elements.