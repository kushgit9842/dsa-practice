// ─────────────────────────────────────────
// Problem : Reverse Integer
// Difficulty: Medium
// Topic    : Math
// Tags     : Math
// Date     : 2026-04-27
// ─────────────────────────────────────────
class Solution {
public:
    int reverse(int x) {
        long res = 0;

        while (x != 0) {
            int digit = x % 10;
            res = res * 10 + digit;

            if (res > INT_MAX || res < INT_MIN) {
                return 0;
            }

            x /= 10;
        }

        return (int)res;
    }
};