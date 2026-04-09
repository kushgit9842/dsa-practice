// Problem: BFS Traversal of Graph
// Platform: GFG / Standard Graph Problem
// Difficulty: Easy

// Approach:
// Use a queue to perform level-order traversal.
// Start from node 0:
// 1. Mark it visited
// 2. Push it into queue
// 3. For each node, visit all unvisited neighbors
// 4. Mark them visited and push into queue

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);   // visited array
        vector<int> ans;         // result
        queue<int> q;            // queue for BFS
        
        // Start from node 0
        q.push(0);
        vis[0] = 1;
        
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);
            
            // Traverse all adjacent nodes
            for (auto it : adj[node]) {

                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};

// Key Learning:
// BFS explores nodes level by level using a queue.