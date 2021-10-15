// Given an integer array nums and an integer k, return true if nums has a 
// continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

// Example 1:

// Input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
// Example 2:

// Input: nums = [23,2,6,4,7], k = 6
// Output: true
// Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
// 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
// Example 3:

// Input: nums = [23,2,6,4,7], k = 13
// Output: false

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k==0) return false;
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            sum %= k;
            // we've seen this before
            if(m.find(sum)!=m.end()){
                if(i - m[sum] >= 2) return true;
            }
            else {
                // we haven't seen it before this so add it to the map
                m[sum] = i;
            }
        }
        return false;
    }
};
