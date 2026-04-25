// ─────────────────────────────────────────
// Problem : Top K Frequent Elements
// Difficulty: Medium
// Topic    : Heap
// Tags     : Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
// Date     : 2026-04-25
// ─────────────────────────────────────────
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            mp[num]++;
        }
        
        //index = frequency
        //Value will be elements
        //bucket[i] = elements occuring ith time
        vector<vector<int>> bucket(n+1);
        
        for(auto &it : mp) {
            int element = it.first;
            int freq    = it.second;
            
            bucket[freq].push_back(element);
        }
        
        //Pick from right to left to find max frequency elements
        vector<int> result;
        for(int i = n; i >= 0; i--) {
            
            if(bucket[i].size() == 0) continue;
            
            int size = bucket.size();
            while(bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
            
        }
        
        return result;
    }
};