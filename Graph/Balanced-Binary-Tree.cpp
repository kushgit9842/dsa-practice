// ─────────────────────────────────────────
// Problem : Balanced Binary Tree
// Difficulty: Easy
// Topic    : Graph
// Tags     : Tree, Depth-First Search, Binary Tree
// Date     : 2026-05-09
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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
    
    // Helper function to calculate the height of a subtree
    int checkBalance(TreeNode* node) {
        // Base case: If the tree is empty, return 0
        if (node == nullptr) {
            return 0;
        }
        
        // Recursively calculate the height of the left and right subtrees
        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1) {
            return -1;  // Left subtree is not balanced
        }
        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1) {
            return -1;  // Right subtree is not balanced
        }
        
        // Check if the current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // Node is not balanced
        }
        
        // Return the height of the current subtree
        return max(leftHeight, rightHeight) + 1;
    }
};