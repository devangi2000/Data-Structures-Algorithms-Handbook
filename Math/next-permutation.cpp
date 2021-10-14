// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory. 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
// Example 4:

// Input: nums = [1]
// Output: [1]

// DO NOT DO THIS in an interview * Facepalm *
/*

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
*/
// DO THIS:

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() <= 1) return;
        int n = nums.size(), k, l, idx=-1;
        // finding the break point of the array
       for(int k = n-1; k>0; k--){
           if(nums[k] > nums[k-1]) {
               idx= k;
               break;}
       }
        if(idx<0){
            reverse(nums.begin(), nums.end());
        }
        else{
            int prev = idx;
            for(int i=idx+1; i<n; i++){
                if(nums[i] > nums[idx-1] and nums[i]<=nums[prev]){
                    prev = i;
                }
            }
            swap(nums[idx-1], nums[prev]);
            reverse(nums.begin()+idx, nums.end());
        }
    }
};
