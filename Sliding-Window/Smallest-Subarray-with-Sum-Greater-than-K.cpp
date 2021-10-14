// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

// A[] = {1, 4, 45, 6, 0, 19}
// x  =  51
// Output: 3
// Explanation:
// Minimum length subarray is 
// {4, 45, 6}

// Example 2:
// Input:
// A[] = {1, 10, 5, 2, 7}
//    x  = 9
// Output: 1
// Explanation:
// Minimum length subarray is {10}
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N, x ≤ 105
// 1 ≤ A[] ≤ 104

class Solution{
public:
    int sb(int arr[], int n, int x)
    {
         int ans = INT_MAX, start = 0, end = 0, sum = 0;
         while(end<n){
             while(sum <= x and end < n){
                 sum += arr[end];
                 end++;
             }
             
             while(sum > x and start < n){
                 ans = min(ans, end - start);
                 sum -= arr[start];
                 start++;
             }
         }
         return ans;
    }
};
