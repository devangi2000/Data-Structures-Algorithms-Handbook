// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
// Example 2:

// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83
// Example 3:

// Input: arr = [1], k = 1
// Output: 1
 

// Constraints:

// 1 <= arr.length <= 500
// 0 <= arr[i] <= 109
// 1 <= k <= arr.length

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        int n = arr.size();
        vector<int> dp(n+1);
        for(int i = 1; i <= n; i++){
            int curMax = 0, best = 0;
            for(int k = 1; k <= K and i - k >= 0; k++){
                curMax = max(curMax, arr[i-k]);
                best = max(best, curMax*k + dp[i-k]);
            }
            dp[i] = best;
        }
        return dp[n];
    }
};
