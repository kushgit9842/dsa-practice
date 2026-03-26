// Problem: Container With Most Water
// Platform: LeetCode
// Link: https://leetcode.com/problems/container-with-most-water/
// Difficulty: Medium

// Approach:
// Use two pointers (left and right).
// Calculate area using: min(height[left], height[right]) * (right - left).
// Move the pointer with smaller height to try and maximize area.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = size(height);
        int left = 0;
        int right = n-1;
        
        int vm = 0;
        while(left<right){
            int vc= min(height[left], height[right])*(right-left);
            vm=max(vm,vc);
            if (height[left]<height[right]){
                left++;
            } 
            else {
                right--;
            }
        }  
        return vm;
    }
};

// Key Learning:
// Two-pointer technique helps reduce time complexity from O(n^2) to O(n).