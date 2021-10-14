// Given an array of integers nums and an integer k, return the total number of continuous
//  subarrays whose sum equals to k.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m;
        m[0] = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == k) count++;
            if(m.find(sum - k) != m.end())
                count += m[sum - k];
            m[sum]++ ;               
        }
        return count;
    }
};