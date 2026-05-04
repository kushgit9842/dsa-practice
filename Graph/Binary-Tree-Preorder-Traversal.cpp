// ─────────────────────────────────────────
// Problem : Binary Tree Preorder Traversal
// Difficulty: Easy
// Topic    : Graph
// Tags     : Stack, Tree, Depth-First Search, Binary Tree
// Date     : 2026-05-04
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
    void preorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        
        result.push_back(root->val);   // root
        preorder(root->left, result);  // left
        preorder(root->right, result); // right
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};