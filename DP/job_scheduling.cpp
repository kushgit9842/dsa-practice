// Problem: Maximum Profit in Job Scheduling
// Platform: LeetCode
// Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Difficulty: Hard

// Approach:
// 1. Combine startTime, endTime, profit into a single array.
// 2. Sort jobs based on start time.
// 3. For each job, we have two choices:
//    - Take the job → add profit + solve next non-overlapping job
//    - Skip the job → move to next job
// 4. Use binary search to find next valid job (non-overlapping).
// 5. Use memoization to avoid recomputation.

// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[50001];
    int n;

    // Find the first job whose start time >= current job's end time
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n + 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
    
    int solve(vector<vector<int>>& array, int i) {
        if (i >= n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int next = getNextIndex(array, i + 1, array[i][1]);

        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i + 1);

        return memo[i] = max(taken, notTaken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        memset(memo, -1, sizeof(memo));

        vector<vector<int>> array(n, vector<int>(3, 0)); // {start, end, profit}

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        // Sort jobs based on start time
        auto comp = [&](auto& vec1, auto& vec2) {
            return vec1[0] <= vec2[0];
        };

        sort(begin(array), end(array), comp);

        return solve(array, 0);
    }
};

// Key Learning:
// Combining DP with binary search helps optimize overlapping interval problems.