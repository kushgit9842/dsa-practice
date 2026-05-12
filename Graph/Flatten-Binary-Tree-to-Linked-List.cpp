// ─────────────────────────────────────────
// Problem : Flatten Binary Tree to Linked List
// Difficulty: Medium
// Topic    : Graph
// Tags     : Linked List, Stack, Tree, Depth-First Search, Binary Tree
// Date     : 2026-05-12
// ─────────────────────────────────────────
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root != nullptr) {
            flattenHelper(root);
        }
    }

    TreeNode* flattenHelper(TreeNode* node) {
        if (node == nullptr) return nullptr;

        TreeNode* leftTail = flattenHelper(node->left);
        TreeNode* rightTail = flattenHelper(node->right);

        if (node->left != nullptr) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }

        return (rightTail != nullptr) ? rightTail : (leftTail != nullptr) ? leftTail : node;
    }
};