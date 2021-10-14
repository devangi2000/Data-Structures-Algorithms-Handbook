// Given an array of integers nums and an integer k,
// return the total number of continuous subarrays whose sum equals to k. 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

// https://www.youtube.com/watch?v=HbbYPQc-Oo4&t=525s

class Solution {
public:
    // Using the Optimized, single traversal algorithm with O(N) time complexity instead of the O(N*N) approach
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        int count = 0, i = 0;
        unordered_map<int,int> m;
        int current_sum = 0;
        while(i<n){
            current_sum += nums[i];
            if(current_sum == k) count++;
            if(m.find(current_sum - k) != m.end()) count += m[current_sum-k];
            m[current_sum]++;
            i++;
        }
        return count;
    }
};
