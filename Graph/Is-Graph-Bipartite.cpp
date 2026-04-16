// ─────────────────────────────────────────
// Problem : Is Graph Bipartite?
// Difficulty: Medium
// Topic    : Graph
// Tags     : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
// Date     : 2026-04-16
// ─────────────────────────────────────────
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs(int u, int c, vector<int>& color, vector<vector<int>>& graph) {
        color[u] = c;

        for (int v : graph[u]) {
            if (color[v] == -1) {
                if (!dfs(v, 1 - c, color, graph)) {
                    return false;
                }
            } else if (color[v] == c) {
                return false;
            }
        }

        return true;
    }
};