// ─────────────────────────────────────────
// Problem : Sort Characters By Frequency
// Difficulty: Medium
// Topic    : Heap
// Tags     : Hash Table, String, Sorting, Heap (Priority Queue), Bucket Sort, Counting
// Date     : 2026-04-25
// ─────────────────────────────────────────
class Solution {
public:
    string frequencySort(string s) {
        // Count the frequency of each character
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Create a priority queue to store characters and their frequencies
        priority_queue<pair<int, char>> pq;
        for (auto& pair : freqMap) {
            pq.push({pair.second, pair.first});
        }

        // Create the result string
        string result;
        while (!pq.empty()) {
            int freq = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            // Append the character to the result string 'freq' times
            for (int i = 0; i < freq; i++) {
                result.push_back(c);
            }
        }

        return result;
    }
};