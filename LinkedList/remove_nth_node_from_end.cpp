// Problem: Remove Nth Node From End of List
// Platform: LeetCode
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Difficulty: Medium

// Approach:
// Use two pointers (fast and slow) with a dummy node.
// Move fast pointer n steps ahead.
// Then move both pointers until fast reaches the end.
// Slow will be just before the node to remove.
// Adjust pointers to remove the target node.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches last node
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from end
        slow->next = slow->next->next;

        return dummy->next;
    }
};

// Key Learning:
// Maintaining a gap of n between fast and slow helps locate the target node in one pass.