// ─────────────────────────────────────────
// Problem : Kth Smallest Element in a Sorted Matrix
// Difficulty: Medium
// Topic    : Heap
// Tags     : Array, Binary Search, Sorting, Heap (Priority Queue), Matrix
// Date     : 2026-04-26
// ─────────────────────────────────────────
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> min_heap;
        
        // Push the first element of each row into the heap
        for (int i = 0; i < matrix.size(); i++) {
            min_heap.push({matrix[i][0], i, 0});
        }
        
        int result = 0;
        // Remove the smallest element from the heap k times
        for (int i = 0; i < k; i++) {
            auto [val, row, col] = min_heap.top();
            min_heap.pop();
            result = val;
            
            // Push the next element from the same row into the heap
            if (col + 1 < matrix.size()) {
                min_heap.push({matrix[row][col + 1], row, col + 1});
            }
        }
        
        return result;
    }
};