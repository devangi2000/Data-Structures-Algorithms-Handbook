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

class Solution {
     public int[] sortArray(int[] nums) {
    	QuickSort(nums, 0, nums.length - 1);
    	int result[] = new int[nums.length]; 
        for (int i = 0; i < nums.length; i++) {
        	result[i] = nums[i];
        }
        return result;
    }
    
    public static void QuickSort(int nums[], int lhs, int rhs) {
    	if(lhs >= rhs) return; 
		int mid = Partition(nums, lhs, rhs);
		QuickSort(nums, lhs, mid);
		QuickSort(nums, mid + 1, rhs);
    }
    
    public static void Swap(int[] nums, int lhs, int rhs) {
    	int temp = nums[lhs];
    	nums[lhs] = nums[rhs]; 
    	nums[rhs] = temp;
    }
    
    public static int Partition(int[] nums, int lhs, int rhs) {
    	int pivot = nums[lhs];
    	while(lhs < rhs) {
            while (lhs < rhs && nums[rhs] >= pivot) rhs--;
            Swap(nums, lhs, rhs);
            while (lhs < rhs && nums[lhs] <= pivot) lhs++;
            Swap(nums, rhs, lhs);
    	}
    	nums[lhs] = pivot;
    	return lhs;
    }
}