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
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length == 0 || intervals == null) return 0;
        int ans = 0;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));        
        for(int i = 1; i < intervals.length; i++){
            if(intervals[i][0] < intervals[i-1][1]){
                intervals[i][1] = Math.min(intervals[i][1], intervals[i-1][1]);
                ans++;
            }
        }
        return ans;
    }
};
