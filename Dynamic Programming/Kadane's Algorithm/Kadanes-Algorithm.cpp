// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#

// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.
// Example 2:

// Input:
// N = 4
// arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 106
// -107 ≤ A[i] ≤ 107

  public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int tillnow = arr[0], cursum = arr[0];
        for(int i = 1; i < n; i++){
            cursum = max(cursum + arr[i], arr[i]);
            tillnow = max(tillnow, cursum);
        }
        return tillnow;
    }
};
