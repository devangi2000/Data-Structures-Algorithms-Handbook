// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 // Constraints:
// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> fromBegin(n);
        fromBegin[0]=1;
        vector<int> fromLast(n);
        fromLast[0]=1;
        
        for(int i=1;i<n;i++){
            fromBegin[i]=fromBegin[i-1]*nums[i-1];
            fromLast[i]=fromLast[i-1]*nums[n-i];
        }
        
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=fromBegin[i]*fromLast[n-1-i];
        }
        return res;
    }
};


// OPTIMIZED

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), left = 1, right = 1;
        vector<int> result(n, 1);
        
        for(int i = 0; i < n; i++){
            result[i] *= left;
            left *= nums[i];
            result[n-i-1] *= right;
            right *= nums[n-i-1];
        }
        return result;
    }
};

// OR MORE UNDERSTANDABLE AND LONGER

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), left = 1, right = 1;
        vector<int> result(n);        
        for(int i = 0; i < n; i++){
            left *= nums[i];
            result[i] = left;
        }
        
        for(int i = n-1; i > 0; i--){
            result[i] = result[i-1]*right;
            right *= nums[i];
        }
        result[0] = right;
        return result;
    }
};

