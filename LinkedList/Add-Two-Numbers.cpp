// ─────────────────────────────────────────
// Problem : Add Two Numbers
// Difficulty: Medium
// Topic    : LinkedList
// Tags     : Linked List, Math, Recursion
// Date     : 2026-04-10
// ─────────────────────────────────────────
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify result list creation
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int carry = 0;

        // Loop while there are digits left or carry exists
        while (l1 != NULL || l2 != NULL || carry) {

            int sum = carry;

            // Add l1 digit if exists
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add l2 digit if exists
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Create new node with digit
            tail->next = new ListNode(sum % 10);

            // Update carry
            carry = sum / 10;

            // Move tail forward
            tail = tail->next;
        }

        return dummy->next;  // real head
    }
};