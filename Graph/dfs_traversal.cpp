// Problem: DFS Traversal of Graph
// Platform: GFG / Standard Graph Problem
// Difficulty: Easy

// Approach:
// Use recursion to perform Depth First Search (DFS).
// Start from node 0:
// 1. Mark node as visited
// 2. Add it to result
// 3. Recursively visit all unvisited neighbors

// Time Complexity: O(V + E)
// Space Complexity: O(V) + recursion stack

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfsHelper(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans) {

        vis[node] = 1;           // mark visited
        ans.push_back(node);     // add to result
        
        // visit all neighbors
        for (auto it : adj[node]) {

            if (!vis[it]) {
                dfsHelper(it, adj, vis, ans);
            }
        }
    }
  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);
        vector<int> ans;
        
        // start DFS from node 0
        dfsHelper(0, adj, vis, ans);
        
        return ans;
    }
};

// Key Learning:
// DFS explores as deep as possible before backtracking.