// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
//   You may assume that the majority element always exists in the array. 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2 

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -231 <= nums[i] <= 231 - 1


// Approach 1 : Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
             }
            if(candidate == nums[i])
                count++;
            else
                count--;
        }
        return candidate;
    }
};


// Approach 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// Approach 3
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto a : nums)
            m[a]++;
        for(auto el : m)
            if(el.second >= (nums.size()+1)/2)
                return el.first;
        return -1;
    }
};
