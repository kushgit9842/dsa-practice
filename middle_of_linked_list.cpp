// Problem: Middle of the Linked List
// Platform: LeetCode
// Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Difficulty: Easy

// Approach:
// Use two pointers: slow and fast.
// Slow moves one step at a time, fast moves two steps.
// When fast reaches the end, slow will be at the middle.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* f = head; // fast pointer
        ListNode* s = head; // slow pointer

        while (f != NULL && f->next != NULL) {
            s = s->next;           // move slow by 1
            f = f->next->next;     // move fast by 2
        }

        return s; // slow pointer will be at middle
    }
};

// Key Learning:
// Fast and slow pointer technique helps solve problems efficiently in one pass.