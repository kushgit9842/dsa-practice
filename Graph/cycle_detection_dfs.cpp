// Problem: Detect Cycle in Undirected Graph (DFS)
// Platform: GFG / Standard Graph Problem
// Difficulty: Medium

// Approach:
// Use DFS with parent tracking.
// For each unvisited node:
//   - Mark it visited
//   - Traverse its neighbors
//   - If a neighbor is visited and not parent → cycle exists

// Time Complexity: O(V + E)
// Space Complexity: O(V) + recursion stack

#include <bits/stdc++.h>
using namespace std;

bool isCycleUtil(vector<int> g[], int start, vector<bool>& visited, int parent) {

    visited[start] = true;
    
    for (auto it = g[start].begin(); it != g[start].end(); it++) {

        // Skip parent node
        if (*it == parent)
            continue;

        // If already visited → cycle
        if (visited[*it] == true)
            return true;

        // DFS on unvisited node
        if (isCycleUtil(g, *it, visited, start))
            return true;
    }

    return false;
}

bool isCyclic(vector<int> g[], int V) {

    vector<bool> visited(V, false);
    
    // Check all components
    for (int i = 0; i < V; i++) {

        if (visited[i] == false && isCycleUtil(g, i, visited, -1))
            return true;
    }

    return false;
}

// Key Learning:
// In DFS, revisiting a node (other than parent) indicates a cycle.