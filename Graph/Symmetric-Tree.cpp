// ─────────────────────────────────────────
// Problem : Symmetric Tree
// Difficulty: Easy
// Topic    : Graph
// Tags     : Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Date     : 2026-05-14
// ─────────────────────────────────────────
 */\nclass Solution {\npublic:\n    bool check(TreeNode* l , TreeNode* r){\n        if (l==NULL && r==NULL){\n    }\n            return true;\n        }\n        if (l==NULL || r==NULL ){\n            return false;\n        }\n        if((l->val == r->val) && check(l->left,r->right) && check(l->right,r->left)){\n            return true; \n        }\n        return false;\n * };\n *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}\n *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}\n *     TreeNode() : val(0), left(nullptr), right(nullptr) {}\n *     TreeNode *right;\n[1,2,2,3,4,4,3]\n[1,2,2,null,3,null,3]\ntrue\nfalse\ntrue\nfalse\n