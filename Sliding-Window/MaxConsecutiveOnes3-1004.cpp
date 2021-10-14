// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if
//  you can flip at most k 0's.
// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 
// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length



/*       1. The question translates to finding the max length of subArray with at most K 0s.
        2. Use sliding window technique.
        3. Keep count of the number of 0s found in the current window.
        4. If the count is > K, then increment l until the count goes to <=K.
        5. At each iteration find the maxLen.
    
    */
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0, n = nums.size(), maxi = 0, start = 0;
        for(int end = 0; end < n; end++){
            if(nums[end] == 0) zeros++;
            while(zeros > k){
                if(nums[start] == 0) zeros--;
                start++;
            }
            maxi = max(maxi, end - start + 1);
        }
        return maxi;
    }
};