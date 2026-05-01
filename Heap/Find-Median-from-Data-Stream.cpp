// ─────────────────────────────────────────
// Problem : Find Median from Data Stream
// Difficulty: Hard
// Topic    : Heap
// Tags     : Two Pointers, Design, Sorting, Heap (Priority Queue), Data Stream
// Date     : 2026-05-01
// ─────────────────────────────────────────
class MedianFinder {
private:
    // Max heap for the smaller half
    priority_queue<int, vector<int>, less<int>> lower_half;
    // Min heap for the larger half
    priority_queue<int, vector<int>, greater<int>> upper_half;

public:
    MedianFinder() {}

    void addNum(int num) {
        // Add to max heap if empty or if num is smaller than the top of max heap
        if (lower_half.empty() || num <= lower_half.top()) {
            lower_half.push(num);
        } else {
            upper_half.push(num);
        }

        // Balance heaps to ensure max heap size is one more than min heap size
        if (lower_half.size() > upper_half.size() + 1) {
            upper_half.push(lower_half.top());
            lower_half.pop();
        } else if (upper_half.size() > lower_half.size()) {
            lower_half.push(upper_half.top());
            upper_half.pop();
        }
    }

    double findMedian() {
        // If total number of elements is odd, return the top of the max heap
        if (lower_half.size() > upper_half.size()) {
            return (double)lower_half.top();
        } 
        // If total number of elements is even, return the average of the tops of the max and min heaps
        return (lower_half.top() + upper_half.top()) / 2.0;
    }
};