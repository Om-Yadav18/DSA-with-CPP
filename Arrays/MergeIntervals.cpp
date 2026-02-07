// LeetCode 56 - Merge Intervals
// Approach:
// 1. Sort intervals by starting time.
// 2. Initialize start and end using the first interval.
// 3. Traverse remaining intervals and merge overlapping ones.
// 4. Store non-overlapping intervals and return the result.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end   = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end   = intervals[i][1];
            }
        }

        ans.push_back({start, end});
        return ans;
    }
};
