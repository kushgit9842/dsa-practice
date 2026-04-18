// ─────────────────────────────────────────
// Problem : Find if Path Exists in Graph
// Difficulty: Easy
// Topic    : Graph
// Tags     : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
// Date     : 2026-04-18
// ─────────────────────────────────────────
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create adjacency list
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Initialize visited set
        vector<bool> visited(n, false);

        // Perform DFS
        return dfs(graph, source, destination, visited);
    }

    bool dfs(const vector<vector<int>>& graph, int vertex, int destination, vector<bool>& visited) {
        // Mark current vertex as visited
        visited[vertex] = true;

        // Check if current vertex is the destination
        if (vertex == destination) {
            return true;
        }

        // Explore neighboring vertices
        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor] && dfs(graph, neighbor, destination, visited)) {
                return true;
            }
        }

        // No path found
        return false;
    }
};