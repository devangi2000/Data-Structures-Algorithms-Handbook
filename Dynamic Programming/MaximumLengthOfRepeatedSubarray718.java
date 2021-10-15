// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
// Example 1:

// Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
// Output: 3
// Explanation: The repeated subarray with maximum length is [3,2,1].
// Example 2:

// Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
// Output: 5
 
// Constraints:
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 100

class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int maxi = Integer.MIN_VALUE, n1 = nums1.length, n2 = nums2.length;
        int[][] dp = new int[n1+1][n2+1];
        for(int i = 0; i <= n1; i++){
            for(int j = 0; j <= n2; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;
                maxi = Math.max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
}