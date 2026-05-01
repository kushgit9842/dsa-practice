// ─────────────────────────────────────────
// Problem : Palindrome Number
// Difficulty: Easy
// Topic    : Math
// Tags     : Math
// Date     : 2026-05-01
// ─────────────────────────────────────────
palindrome\n        if (x < 0 || (x % 10 == 0 && x != 0)) return false;\n\n        int reversedHalf = 0;\n\n        while (x > reversedHalf) {\n            reversedHalf = reversedHalf * 10 + x % 10;\n            x /= 10;\n        }\n\n        // For even digits: x == reversedHalf\n        // For odd digits: x == reversedHalf / 10\n        return (x == reversedHalf || x == reversedHalf / 10);\n    }\n        // Negative numbers or ending with 0 (except 0 itself) can't be \n    bool isPalindrome(int x) {\npublic:\nclass Solution {\n121\n-121\n10\ntrue\nfalse\nfalse\ntrue\nfalse\nfalse\n