// Problem: Detect Cycle in Undirected Graph (BFS)
// Platform: GFG / Standard Graph Problem
// Difficulty: Medium

// Approach:
// Use BFS with parent tracking.
// For each unvisited node:
//   - Start BFS
//   - Store (node, parent) in queue
//   - If a visited neighbor is found that is NOT parent → cycle exists

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool isCycleBFS(vector<int> g[], int V, int start, vector<bool>& visited) {

        queue<pair<int, int>> que;
        que.push({start, -1});
        visited[start] = true;

        while (!que.empty()) {

            int curr   = que.front().first;
            int parent = que.front().second;
            que.pop();
            
            for (auto x : g[curr]) {

                if (visited[x] == false) {
                    que.push({x, curr});
                    visited[x] = true;
                }
                else if (x != parent) {
                    return true; // cycle detected
                }
            }
        }
        
        return false;
    }

    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        
        // Check all components
        for (int i = 0; i < V; i++) {

            if (!visited[i] && isCycleBFS(adj, V, i, visited)) {
                return true;
            }
        }
        
        return false;
    }
};

// Key Learning:
// In undirected graphs, a visited node that is not the parent