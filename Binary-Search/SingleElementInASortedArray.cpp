// You are given a sorted array consisting of only integers where every element 
// appears exactly twice, except for one element which appears exactly once. 
// Find this single element that appears only once.

// Follow up: Your solution should run in O(log n) time and O(1) space. 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 
// Constraints:
// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^5

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        // BOUNDARY CONDITIONS
        if(end == 0) return nums[0];
        else if(nums[0] != nums[1]) return nums[0];
        else if(nums[end] != nums[end-1]) return nums[end];
        // BINARY SEARCH
        while(start <= end){
            int mid = (start + end) >> 1;
            if(nums[mid] != nums[mid+1] and nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            else if(((mid%2)==0 and nums[mid] == nums[mid+1]) or 
                    ((mid%2)==1 and nums[mid] == nums[mid-1])){
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return -1;
    }
};