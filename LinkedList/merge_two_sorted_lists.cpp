// Problem: Merge Two Sorted Lists
// Platform: LeetCode
// Link: https://leetcode.com/problems/merge-two-sorted-lists/
// Difficulty: Easy

// Approach:
// Use a dummy node to simplify list merging.
// Compare nodes from both lists and attach the smaller one to the result list.
// Move the pointer forward and continue.
// After one list ends, attach the remaining part of the other list.

// Time Complexity: O(n + m)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0); // dummy head
        ListNode* tail = dummy;            // pointer to build result list

        while (l1 != NULL && l2 != NULL) {

            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next; // move forward
        }

        // Attach remaining nodes (only one of these will run)
        if (l1 != NULL) tail->next = l1;
        if (l2 != NULL) tail->next = l2;

        return dummy->next; // return actual head
    }
};

// Key Learning:
// Dummy node simplifies handling of head pointer and edge cases.