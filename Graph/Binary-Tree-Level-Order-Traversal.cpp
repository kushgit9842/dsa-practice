// ─────────────────────────────────────────
// Problem : Binary Tree Level Order Traversal
// Difficulty: Medium
// Topic    : Graph
// Tags     : Tree, Breadth-First Search, Binary Tree
// Date     : 2026-05-06
// ─────────────────────────────────────────
                TreeNode* node = q.front();\n                q.pop();\n\n                level.push_back(node->val);\n\n                if(node->left)\n                    q.push(node->left);\n\n                if(node->right)\n                    q.push(node->right);\n            }\n\n            ans.push_back(level);\n        }\n\n        return ans;\n    }\n};\n[3,9,20,null,null,15,7]\n[1]\n[]\n[[3],[9,20],[15,7]]\n[[1]]\n[]\n[[3],[9,20],[15,7]]\n[[1]]\n[]\n