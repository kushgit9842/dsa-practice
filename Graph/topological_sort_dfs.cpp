// Problem: Topological Sort (DFS)
// Platform: GFG / Standard Graph Problem
// Difficulty: Medium

// Approach:
// Use DFS + stack.
// 1. Perform DFS traversal
// 2. After visiting all neighbors of a node, push it into stack
// 3. Finally, pop elements from stack → gives topological order

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void DFS(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st) {

        visited[u] = true;
        
        // Visit all neighbors first
        for (int &v : adj[u]) {
            if (!visited[v])
                DFS(adj, v, visited, st);
        }
        
        // Push current node after its children
        st.push(u);
    }
    
    // Function to return list containing vertices in Topological order
    vector<int> topoSort(int V, vector<int> adj[]) {

        vector<bool> visited(V, false);
        stack<int> st;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                DFS(adj, i, visited, st);
        }
        
        vector<int> result;
        
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};

// Key Learning:
// In topological sort, nodes are processed AFTER their dependencies.