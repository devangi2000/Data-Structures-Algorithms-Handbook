// Given an array arr[ ] of length N consisting cost of N 
// toys and an integer K depicting the amount with you. Your task
// is to find maximum number of toys you can buy with K amount. 

// Example 1:

// Input: 
// N = 7 
// K = 50
// arr[] = {1, 12, 5, 111, 200, 1000, 10}
// Output: 4
// Explaination: The costs of the toys 
// you can buy are 1, 12, 5 and 10.
// Example 2:

// Input: 
// N = 3 
// K = 100
// arr[] = {20, 30, 50}
// Output: 3
// Explaination: You can buy all toys.

// Expected Time Complexity: O(N * Log(N))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ K, arr[i] ≤ 109

class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        if(N == 0 or K == 0) return 0;
        sort(arr.begin(), arr.end());
        int count = 0, sum = 0, i=0;
        while(i<N and K - arr[i] >= 0){
            K -= arr[i++];
       }
        return i;
    }
};
