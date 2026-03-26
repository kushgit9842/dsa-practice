// Problem: Reverse Linked List
// Platform: LeetCode
// Link: https://leetcode.com/problems/reverse-linked-list/
// Difficulty: Easy

// Approach:
// Use three pointers: prev, curr, and nextnode.
// Traverse the list and reverse the direction of each node's next pointer.
// Move forward step by step until the end of the list.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextnode = curr->next; // store next node
            curr->next = prev;               // reverse link
            prev = curr;                     // move prev forward
            curr = nextnode;                 // move curr forward
        }

        return prev; // new head of reversed list
    }
};

// Key Learning:
// Iterative reversal uses constant space and updates links in-place.