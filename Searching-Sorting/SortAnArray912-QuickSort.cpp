// Given an array of integers nums, sort the array in ascending order.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -5 * 104 <= nums[i] <= 5 * 104


// QuickSort that gives TLE
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void quickSort(vector<int> &nums, int left, int right){
        if(left >= right) return;
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid);
        quickSort(nums, mid + 1, right);
        return;
    }
    
    int partition(vector<int> &nums, int left, int right){
        int pivot = nums[left];
        while(left < right){
            while(left < right and nums[right] >= pivot)
                right--;
            nums[left] = nums[right];
            while(left < right and nums[left] <= pivot)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

// Randomized 

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }    

    int partitionArray(vector<int> &nums, int low, int high) {
        if (low >= high) return -1;
        int pivot = low, l = pivot + 1, r = high;
        while (l <= r)
            if (nums[l] < nums[pivot]) l++;
            else if (nums[r] >= nums[pivot]) r--;
            else swap(nums[l], nums[r]);
        swap(nums[pivot], nums[r]);
        return r;
    }

    void quickSort(vector<int> &nums, int low, int high) {
        if (low >= high) return;
        swap(nums[low + rand() % (high - low + 1)], nums[low]);
        int pivot = partitionArray(nums, low, high);
        quickSort(nums, low, pivot);
        quickSort(nums, pivot + 1, high);
    }
};
