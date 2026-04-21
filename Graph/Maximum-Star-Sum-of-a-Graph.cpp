// ─────────────────────────────────────────
// Problem : Maximum Star Sum of a Graph
// Difficulty: Medium
// Topic    : Graph
// Tags     : Array, Greedy, Graph Theory, Sorting, Heap (Priority Queue)
// Date     : 2026-04-21
// ─────────────────────────────────────────
            vector<pair<int, int>> neighbors;\n            for (int neighbor : graph[i]) {\n                neighbors.emplace_back(vals[neighbor], neighbor);\n            }\n            sort(neighbors.rbegin(), neighbors.rend());\n\n            // Try to form a star graph by including the top k \n            int currentStarSum = vals[i];\n            for (int j = 0; j < min(k, (int)neighbors.size()); j++) {\n                currentStarSum += neighbors[j].first;\n            }\n\n            // Update the maximum star sum\n            maxStarSum = max(maxStarSum, currentStarSum);\n        }\n\n        return maxStarSum;\n    }\n};\nneighbors\n[1,2,3,4,10,-10,-20]\n[[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]]\n2\n[-5]\n[]\n0\n16\n-5\n16\n-5\n