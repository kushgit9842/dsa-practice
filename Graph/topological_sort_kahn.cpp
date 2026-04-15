// Problem: Topological Sort (Kahn's Algorithm - BFS)
// Platform: GFG / Standard Graph Problem
// Difficulty: Medium

// Approach:
// 1. Compute indegree of all nodes
// 2. Push all nodes with indegree = 0 into queue
// 3. Perform BFS:
//    - Remove node from queue
//    - Add to result
//    - Reduce indegree of neighbors
//    - If indegree becomes 0 → push to queue

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> topoSort(int N, vector<int> adj[]) {

        queue<int> que;
        vector<int> indegree(N, 0);
        
        // Step 1: Calculate indegree
        for (int u = 0; u < N; u++) {
            for (int &v : adj[u]) {
                indegree[v]++;
            }
        }
        
        // Step 2: Push nodes with indegree 0
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        
        // Step 3: BFS
        vector<int> result;

        while (!que.empty()) {

            int u = que.front();
            que.pop();

            result.push_back(u);
            
            for (int &v : adj[u]) {
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        
        return result;
    }
};

// Key Learning:
// Kahn’s Algorithm processes nodes with no dependencies first.