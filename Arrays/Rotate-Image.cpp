// ─────────────────────────────────────────
// Problem : Rotate Image
// Difficulty: Medium
// Topic    : Arrays
// Tags     : Array, Math, Matrix
// Date     : 2026-04-10
// ─────────────────────────────────────────
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = size(matrix);

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};