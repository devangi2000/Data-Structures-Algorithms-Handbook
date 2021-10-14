Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Follow-up: Could you solve the problem in linear time and in O(1) space?

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if(n == 0) return ans;
        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;
        for(auto num: nums){
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
            else if(count1 == 0){
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(auto num:nums){
            if(num == candidate1) count1+=2;
            else count1--;
            if(num == candidate2) count2 +=2;
            else count2--;
        }
        if(count1 > 0) ans.push_back(candidate1);
        if(count2 > 0) ans.push_back(candidate2);
        return ans;
    }
};
