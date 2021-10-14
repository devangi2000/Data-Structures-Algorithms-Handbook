// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// Example 1:
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 
// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

// BRUTE FORCE : GIVES TLE

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            int zeros = 0, ones = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == 0) zeros++;
                else ones++;
                if(zeros == ones)
                    ans = max(ans, j - i + 1);
            }
        }        
        return ans;
    }
};

// OPTIMIZED

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxi = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] == 0 ? -1 : 1);
            if(sum == 0) maxi = max(maxi, i+1);
            else if(m.find(sum) != m.end()){
                maxi = max(maxi, i - m[sum]);
            }
            else m[sum] = i;                
        }        
        return maxi;
    }
};