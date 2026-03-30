// Problem: Linked List Cycle II
// Platform: LeetCode
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Difficulty: Medium

// Approach:
// 1. Use fast and slow pointers to detect cycle (Floyd’s Algorithm).
// 2. If they meet, a cycle exists.
// 3. Move one pointer to head, keep the other at meeting point.
// 4. Move both one step at a time → they meet at cycle start.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* s = head; // slow pointer
        ListNode* f = head; // fast pointer
        ListNode* p = head; // pointer to find cycle start

        // Step 1: Detect cycle
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;

            if (s == f) {
                break; // cycle detected
            }
        }

        // No cycle
        if (!f || !f->next) return NULL;

        // Step 2: Find cycle start
        while (p != s) {
            p = p->next;
            s = s->next;
        }

        return s; // start of cycle
    }
};

// Key Learning:
// After meeting point, moving one pointer to head ensures both pointers
// meet at the start of the cycle due to equal distance.