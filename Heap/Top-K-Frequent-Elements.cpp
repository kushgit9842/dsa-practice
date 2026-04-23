// ─────────────────────────────────────────
// Problem : Top K Frequent Elements
// Difficulty: Medium
// Topic    : Heap
// Tags     : Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
// Date     : 2026-04-23
// ─────────────────────────────────────────
        //bucket[i] = elements occuring ith time\n        vector<vector<int>> bucket(n+1);\n        \n        for(auto &it : mp) {\n            int element = it.first;\n        for(int &num : nums) {\n            mp[num]++;\n        }\n        \n        //index = frequency\n        //Value will be elements\nclass Solution {\npublic:\n    vector<int> topKFrequent(vector<int>& nums, int k) {\n        int n = nums.size();\n        \n        unordered_map<int, int> mp;\n        \n[1,1,1,2,2,3]\n2\n[1]\n1\n[1,2,1,2,1,2,3,1,3,2]\n2\n[1,2]\n[1]\n[1,2]\n[1,2]\n[1]\n[1,2]\n