// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [1,1]
// Output: 1
// Example 4:

// Input: nums = [1,1,2]
// Output: 1 

// Constraints:

// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.
  

// Two Pointers

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow!=fast);
        
        fast = nums[0];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Hashing
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(auto num: nums){
            m[num]++;
            if(m[num] > 1)
                return num;
        }
        return 0;
    }
};
