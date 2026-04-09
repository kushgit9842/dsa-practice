// ─────────────────────────────────────────
// Problem : Generate Parentheses
// Difficulty: Medium
// Topic    : Strings
// Tags     : String, Dynamic Programming, Backtracking
// Date     : 2026-04-09
// ─────────────────────────────────────────
class Solution {
public:
    void solve(int open, int close, string str, vector<string> &ans, int n) {
        if (str.length() == 2 * n) {
            ans.push_back(str);
            return;
        }

        if (open < n) {
            solve(open + 1, close, str + '(', ans, n);
        }

        if (close < open) {
            solve(open, close + 1, str + ')', ans, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, "", ans, n);
        return ans;
    }
};