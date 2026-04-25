// ─────────────────────────────────────────
// Problem : Sort Characters By Frequency
// Difficulty: Medium
// Topic    : Heap
// Tags     : Hash Table, String, Sorting, Heap (Priority Queue), Bucket Sort, Counting
// Date     : 2026-04-25
// ─────────────────────────────────────────
        }\n\n        // Create a priority queue to store characters and their frequencies\npublic:\n    string frequencySort(string s) {\n        // Count the frequency of each character\n        unordered_map<char, int> freqMap;\n        for (char c : s) {\n            freqMap[c]++;\nclass Solution {\n        priority_queue<pair<int, char>> pq;\n        for (auto& pair : freqMap) {\n            pq.push({pair.second, pair.first});\n        }\n\n        // Create the result string\n        string result;\n        while (!pq.empty()) {\n"tree"\n"cccaaa"\n"Aabb"\n"eetr"\n"cccaaa"\n"bbaA"\n"eert"\n"aaaccc"\n"bbAa"\n