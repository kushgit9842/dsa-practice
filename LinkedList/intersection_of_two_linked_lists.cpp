// Problem: Intersection of Two Linked Lists
// Platform: LeetCode
// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Difficulty: Easy

// Approach:
// Use two pointers (a and b).
// Traverse both lists. When one pointer reaches the end,
// redirect it to the head of the other list.
// If the lists intersect, both pointers will meet at the intersection node.
// If not, both will reach NULL at the same time.

// Time Complexity: O(n + m)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (!headA || !headB) return NULL;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {

            // When reaching end, switch to other list
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;  // intersection node or NULL
    }
};

// Key Learning:
// Switching heads equalizes path lengths, ensuring both pointers
// traverse the same total distance.