// ─────────────────────────────────────────
// Problem : Diameter of Binary Tree
// Difficulty: Easy
// Topic    : Graph
// Tags     : Tree, Depth-First Search, Binary Tree
// Date     : 2026-05-08
// ─────────────────────────────────────────
 */\nclass Solution {\npublic:\n    int ans;\n    int diameterOfBinaryTree(TreeNode* root) {\n        ans = 1;\n        depth(root);\n        return ans - 1;\n    }\n    \n    int depth(TreeNode* node) {\n        if (!node) return 0;\n        int L = depth(node->left);\n        int R = depth(node->right);\n        ans = max(ans, L + R + 1);\n        return max(L, R) + 1;\n    }\n};\n[1,2,3,4,5]\n[1,2]\n3\n1\n3\n1\n