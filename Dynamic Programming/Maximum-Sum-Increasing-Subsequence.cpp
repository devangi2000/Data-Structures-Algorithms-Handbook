// Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 
// Example 1:

// Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
// Output: 106
// Explanation:The maximum sum of a
// increasing sequence is obtained from
// {1, 2, 3, 100}
// Example 2:

// Input: N = 3, arr[] = {1, 2, 3}
// Output: 6
// Explanation:The maximum sum of a
// increasing sequence is obtained from
// {1, 2, 3}

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 103
// 1 ≤ arr[i] ≤ 105

class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
        if(n == 1) return arr[0];
        vector<int> lis;
        for(int i = 0; i < n; ++i)
            lis.push_back(arr[i]);
        int ans = arr[0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i] and lis[i] <= lis[j] + arr[i]){
                    lis[i] = max(lis[i], arr[i] + lis[j]);
                    ans = max(ans, lis[i]);
                }
            }
        }
        return ans;
	}  
};
