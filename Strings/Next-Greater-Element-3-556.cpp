// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n.
// If no such positive integer exists, return -1.
// Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

// Example 1:
// Input: n = 12
// Output: 21
// Example 2:
// Input: n = 21
// Output: -1

// Constraints:
// 1 <= n <= 231 - 1

// using in-built next_permutation: 

class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        next_permutation(digits.begin(), digits.end());
        int res = stoll(digits);
        return (res > INT_MAX or res <= n) ? -1 : res;
    }
};

// doing the next permutation on your own
class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        if(!nextPermutation(nums)) return -1;
        long long result=stoll(nums);
        return (result>INT_MAX || result<=n)? -1:result;
    }
private:
    bool nextPermutation(string& nums) {
        if(nums.empty()) return false;
        int i=nums.size()-1;
        while(i>=1 && nums[i]<=nums[i-1]) i--;
        if(i==0) return false; // no next permutation, i.e. already largest
        
        int j=nums.size()-1;
        while(nums[j]<=nums[i-1]) j--;
        swap(nums[i-1],nums[j]);
        
        reverse(nums.begin()+i,nums.end());
        return true;
    }
};
