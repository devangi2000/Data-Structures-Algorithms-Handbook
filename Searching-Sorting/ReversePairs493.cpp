// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

// Example 1:
// Input: nums = [1,3,2,3,1]
// Output: 2
// Example 2:
// Input: nums = [2,4,3,5,1]
// Output: 3

// Constraints:
// 1 <= nums.length <= 5 * 104
// -231 <= nums[i] <= 231 - 1

class Solution {
public:
    int merge(vector<int> &nums, int left, int mid, int right){
        int count = 0, j = mid + 1;
        for(int i = left; i <= mid; i++){
            while(j <= right && nums[i] > (2 * (long long int) nums[j]))
                j++;
            count += (j - (mid + 1));
        }
        vector<int> temp;
        int low = left, high = mid + 1;
        while(low <= mid and high <= right){
            if(nums[low] <= nums[high])
                temp.push_back(nums[low++]);
            else temp.push_back(nums[high++]);
        }
        while(low <= mid)
            temp.push_back(nums[low++]);
        while(high <= right)
            temp.push_back(nums[high++]);
        for(int i = left; i <= right; i++)
            nums[i] = temp[i-left];
        return count;
    }
    
    int mergeSort(vector<int> &nums, int left, int right){
        if(left >= right) return 0;
        int mid = left + (right - left) / 2;
        int inv = mergeSort(nums, left, mid);
        inv += mergeSort(nums, mid+1, right);
        inv += merge(nums, left, mid, right);
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};