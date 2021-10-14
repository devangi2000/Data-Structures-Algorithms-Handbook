// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 3:

// Input: nums = [1]
// Output: 1


  // NOT CONSTANT SPACE
  
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num:nums){
            m[num]++;
      }
        for(auto num:nums)
            if(m[num]==1) return num;
        return -1;
    }
};


// CONSTANT SPACE

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto a : nums)
            ans ^= a;
        return ans;
    }
};