// Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

// The value of |x| is defined as:

// x if x >= 0.
// -x if x < 0.
 

// Example 1:

// Input: nums = [1,2,2,1], k = 1
// Output: 4
// Explanation: The pairs with an absolute difference of 1 are:
// - [1,2,2,1]
// - [1,2,2,1]
// - [1,2,2,1]
// - [1,2,2,1]
// Example 2:

// Input: nums = [1,3], k = 3
// Output: 0
// Explanation: There are no pairs with an absolute difference of 3.
// Example 3:

// Input: nums = [3,2,1,5,4], k = 2
// Output: 3
// Explanation: The pairs with an absolute difference of 2 are:
// - [3,2,1,5,4]
// - [3,2,1,5,4]
// - [3,2,1,5,4]
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
// 1 <= k <= 99


// BRUTE FORCE

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++)
            for(int j = i+1; j < nums.size(); j++)
                if(abs(nums[j] - nums[i]) == k)
                    ++count;
        return count;
    }
};

// HASHING

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            count += m[nums[i] + k] > 0 ? m[nums[i] + k] : 0;
            count += m[nums[i] - k] > 0 ? m[nums[i] - k] : 0;
            m[nums[i]]++;
        }            
        return count;
    }
};
