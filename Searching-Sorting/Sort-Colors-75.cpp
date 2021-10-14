// Given an array nums with n objects colored red, white, or blue, sort them in-place
// so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
// Example 3:

// Input: nums = [0]
// Output: [0]
// Example 4:

// Input: nums = [1]
// Output: [1]
// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is 0, 1, or 2.

// METHOD 1:
// Plain sorting

// METHOD 2: Counting Sort

// METHOD 3: Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0, right=nums.size()-1, mid=0;
        while(mid<=right)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[left++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[right--]);
                    break;
            }
        }
    }
};
