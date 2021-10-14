// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number
//  of intervals you need to remove to make the rest of the intervals non-overlapping.

// Example 1:
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:
// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:
// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Constraints:
// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        int ans = -1;
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> prev = intervals[0];
        for(auto interval : intervals){
            if(interval[0] < prev[1]) // overlapping
                ans++;
            else
                prev = interval; // non-overlapping
        }
        return ans;
    }
};

