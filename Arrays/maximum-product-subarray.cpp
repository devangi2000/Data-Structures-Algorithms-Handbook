// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// It is guaranteed that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

class Solution {
public:
    
    // time complexity is O(N) and space O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int maxOverall = nums[0];
        int max_ending_here = nums[0], min_ending_here = nums[0];
        
        for(int i=1; i<n; i++){
            int temp = max_ending_here;
            max_ending_here = max({nums[i], nums[i]*max_ending_here, nums[i]*min_ending_here});
            min_ending_here = min({nums[i], nums[i]*temp, nums[i]*min_ending_here});
            maxOverall = max(maxOverall, max_ending_here);
        }
        return maxOverall;
    }
};
