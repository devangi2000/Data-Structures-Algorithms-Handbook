// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

 

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
// Example 3:

// Input: intervals = [], newInterval = [5,7]
// Output: [[5,7]]
// Example 4:

// Input: intervals = [[1,5]], newInterval = [2,3]
// Output: [[1,5]]
// Example 5:

// Input: intervals = [[1,5]], newInterval = [2,7]
// Output: [[1,7]]
 

// Constraints:

// 0 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 105
// intervals is sorted by starti in ascending order.
// newInterval.length == 2
// 0 <= start <= end <= 105

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int begin = 0, n = intervals.size();
        vector<vector<int>> res;
        // First, put all intervals that are to the left of the inserted interval.
        while(begin < n and intervals[begin][1] < newInterval[0]){
            res.push_back(intervals[begin++]);
        }
        // Second, merge all intervals that intersect with the inserted interval.
        while(begin < n and intervals[begin][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[begin][0]);
            newInterval[1] = max(newInterval[1], intervals[begin][1]);
            begin++;
        }
        res.push_back(newInterval);
        // Finally, put all intervals that are to the right of the inserted interval.
        while(begin < n)
            res.push_back(intervals[begin++]);
        return res;
    }
};



