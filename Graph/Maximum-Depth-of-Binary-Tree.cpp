// ─────────────────────────────────────────
// Problem : Maximum Depth of Binary Tree
// Difficulty: Easy
// Topic    : Graph
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Date     : 2026-05-08
// ─────────────────────────────────────────
 * };\n */\nclass Solution {\npublic:\n    int maxDepth(TreeNode* root) {\n        // Base Case: empty tree\n        if (root == nullptr) {\n            return 0;\n        }\n        \n        // Recursive Case: calculate max depth of left and right subtrees\n        int leftDepth = maxDepth(root->left);\n        int rightDepth = maxDepth(root->right);\n        \n        // Return max depth of subtrees plus one for current node\n        return std::max(leftDepth, rightDepth) + 1;\n    }\n};\n[3,9,20,null,null,15,7]\n[1,null,2]\n3\n2\n3\n2\n