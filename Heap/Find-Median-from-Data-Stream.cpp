// ─────────────────────────────────────────
// Problem : Find Median from Data Stream
// Difficulty: Hard
// Topic    : Heap
// Tags     : Two Pointers, Design, Sorting, Heap (Priority Queue), Data Stream
// Date     : 2026-04-24
// ─────────────────────────────────────────
\n            upper_half.push(num);\n        }\n        // Add to max heap if empty or if num is smaller than the top of max heap\n        if (lower_half.empty() || num <= lower_half.top()) {\n            lower_half.push(num);\n        } else {\n\npublic:\n    MedianFinder() {}\n\n    void addNum(int num) {\n    // Max heap for the smaller half\n    priority_queue<int, vector<int>, less<int>> lower_half;\n    // Min heap for the larger half\n    priority_queue<int, vector<int>, greater<int>> upper_half;\nclass MedianFinder {\nprivate:\n["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]\n[null,null,null,1.50000,null,2.00000]\n[null,null,null,1.50000,null,2.00000]\n