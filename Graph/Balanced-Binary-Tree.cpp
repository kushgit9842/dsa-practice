// ─────────────────────────────────────────
// Problem : Balanced Binary Tree
// Difficulty: Easy
// Topic    : Graph
// Tags     : Tree, Depth-First Search, Binary Tree
// Date     : 2026-05-09
// ─────────────────────────────────────────
        }\n        int rightHeight = checkBalance(node->right);\n        if (rightHeight == -1) {\n            return -1;  // Right subtree is not balanced\n        }\n        \n        // Check if the current node is balanced\n        if (abs(leftHeight - rightHeight) > 1) {\n            return -1;  // Node is not balanced\n        }\n        \n        // Return the height of the current subtree\n        return max(leftHeight, rightHeight) + 1;\n    }\n[3,9,20,null,null,15,7]\n[1,2,2,3,3,null,null,4,4]\n[]\ntrue\nfalse\ntrue\ntrue\nfalse\ntrue\n