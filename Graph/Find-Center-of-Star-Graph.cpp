// ─────────────────────────────────────────
// Problem : Find Center of Star Graph
// Difficulty: Easy
// Topic    : Graph
// Tags     : Graph Theory
// Date     : 2026-04-20
// ─────────────────────────────────────────
        int n = edges.size() + 1;\n        vector<int> count(n + 1, 0);\n        \n        // Iterate through each edge and increment the count for each \n        for (auto& edge : edges) {\n            count[edge[0]]++;\n            count[edge[1]]++;\n        }\n        \n        // Find the node with the highest degree\n        int center = 0;\n        for (int i = 1; i <= n; i++) {\n            if (count[i] > count[center]) {\n                center = i;\n            }\n        }\n        \nnode\n        // Count the occurrences of each node\n    int findCenter(vector<vector<int>>& edges) {\npublic:\nclass Solution {\n[[1,2],[2,3],[4,2]]\n[[1,2],[5,1],[1,3],[1,4]]\n2\n1\n2\n1\n