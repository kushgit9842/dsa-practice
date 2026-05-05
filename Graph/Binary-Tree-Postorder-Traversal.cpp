// ─────────────────────────────────────────
// Problem : Binary Tree Postorder Traversal
// Difficulty: Easy
// Topic    : Graph
// Tags     : Stack, Tree, Depth-First Search, Binary Tree
// Date     : 2026-05-05
// ─────────────────────────────────────────
        while (!st1.empty()) {\n            TreeNode* curr = st1.top();\n            st1.pop();\n\n            st2.push(curr);\n\n            if (curr->left) st1.push(curr->left);\n            if (curr->right) st1.push(curr->right);\n        st1.push(root);\n\n        if (root == nullptr) return postorder;\n\n        stack<TreeNode*> st1, st2;\npublic:\n    vector<int> postorderTraversal(TreeNode* root) {\n        vector<int> postorder;\n\nclass Solution {\n[1,null,2,3]\n[1,2,3,4,5,null,8,null,null,6,7,9]\n[]\n[1]\n[3,2,1]\n[4,6,7,5,2,9,8,3,1]\n[]\n[1]\n[3,2,1]\n[4,6,7,5,2,9,8,3,1]\n[]\n[1]\n