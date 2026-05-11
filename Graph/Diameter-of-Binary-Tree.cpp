// ─────────────────────────────────────────
// Problem : Diameter of Binary Tree
// Difficulty: Easy
// Topic    : Graph
// Tags     : Tree, Depth-First Search, Binary Tree
// Date     : 2026-05-11
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
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
    
    int depth(TreeNode* node) {
        if (!node) return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1;
    }
};