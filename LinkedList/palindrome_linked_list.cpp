// Problem: Palindrome Linked List
// Platform: LeetCode
// Link: https://leetcode.com/problems/palindrome-linked-list/
// Difficulty: Easy

// Approach:
// 1. Use fast and slow pointers to find the middle of the list.
// 2. Reverse the second half of the list.
// 3. Compare the first half and reversed second half.
// 4. If all values match → palindrome.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};

// Key Learning:
// Reverse second half of linked list to compare values efficiently in O(1) space.