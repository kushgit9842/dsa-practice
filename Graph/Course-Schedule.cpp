// ─────────────────────────────────────────
// Problem : Course Schedule
// Difficulty: Medium
// Topic    : Graph
// Tags     : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
// Date     : 2026-04-14
// ─────────────────────────────────────────
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list
        vector<vector<int>> graph(numCourses);
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }

        // Initialize visited array
        vector<int> visited(numCourses, -1);

        // Perform DFS on each unvisited course
        for (int course = 0; course < numCourses; course++) {
            if (visited[course] == -1 && !dfs(graph, visited, course)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(const vector<vector<int>>& graph, vector<int>& visited, int course) {
        // Mark course as visiting
        visited[course] = 0;

        // Visit all prerequisites
        for (const auto& prerequisite : graph[course]) {
            if (visited[prerequisite] == 0) {
                // Cycle detected
                return false;
            } else if (visited[prerequisite] == -1) {
                if (!dfs(graph, visited, prerequisite)) {
                    return false;
                }
            }
        }

        // Mark course as visited
        visited[course] = 1;

        return true;
    }
};