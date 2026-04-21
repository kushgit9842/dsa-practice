// ─────────────────────────────────────────
// Problem : Find Center of Star Graph
// Difficulty: Easy
// Topic    : Graph
// Tags     : Graph Theory
// Date     : 2026-04-21
// ─────────────────────────────────────────
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Count the occurrences of each node
        int n = edges.size() + 1;
        vector<int> count(n + 1, 0);
        
        // Iterate through each edge and increment the count for each node
        for (auto& edge : edges) {
            count[edge[0]]++;
            count[edge[1]]++;
        }
        
        // Find the node with the highest degree
        int center = 0;
        for (int i = 1; i <= n; i++) {
            if (count[i] > count[center]) {
                center = i;
            }
        }
        
        return center;
    }
};