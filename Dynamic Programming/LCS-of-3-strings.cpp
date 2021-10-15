// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1#
// Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

// Example 1:

// Input:
// A = "geeks", B = "geeksfor", 
// C = "geeksforgeeks"
// Output: 5
// Explanation: "geeks"is the longest common
// subsequence with length 5.
// â€‹Example 2:

// Input: 
// A = "abcd", B = "efgh", C = "ijkl"
// Output: 0
// Explanation: There's no common subsequence
// in all the strings.

// Expected Time Complexity: O(n1*n2*n3).
// Expected Auxiliary Space: O(n1*n2*n3).

// Constraints:
// 1<=n1, n2, n3<=100

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1+1][n2+1][n3+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <=n1; i++){
        for(int j = 1; j <=n2; j++){
            for(int k = 1; k <=n3; k++){
                if(A[i-1]==B[j-1] and B[j-1]==C[k-1])
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                else
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }
        }
    }
    return dp[n1][n2][n3];
}
