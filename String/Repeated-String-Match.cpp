// ─────────────────────────────────────────
// Problem : Repeated String Match
// Difficulty: Medium
// Topic    : String
// Tags     : String, String Matching
// Date     : 2026-04-12
// ─────────────────────────────────────────
        string repeatedA = a;\n        for (int i = 1; i < count; i++) {\n            repeatedA += a;\n        }\n        \n        // Check if b is a substring of the repeated string a\n        if (repeatedA.find(b) != string::npos) {\n            return count;\n        }\n        \n        // Check if b is a substring of the repeated string a repeated \none more time\n        repeatedA += a;\n        if (repeatedA.find(b) != string::npos) {\n            return count + 1;\n        }\n        \n        // If b is not a substring of the repeated string a, return -1\n        return -1;\n    }\n};\n"abcd"\n"cdabcdab"\n"a"\n"aa"\n3\n2\n3\n2\n