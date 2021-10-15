// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#

// Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

// Matrix [r+1] [c]
// Matrix [r+1] [c-1]
// Matrix [r+1] [c+1]
// Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

// Example 1:

// Input: N = 2
// Matrix = {{348, 391},
//           {618, 193}}
// Output: 1009
// Explaination: The best path is 391 -> 618. 
// It gives the sum = 1009.

// Example 2:

// Input: N = 2
// Matrix = {{2, 2},
//           {2, 2}}
// Output: 4
// Explaination: No matter which path is 
// chosen, the output is 4.

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N)

// Constraints:
// 1 ≤ N ≤ 500
// 1 ≤ Matrix[i][j] ≤ 1000

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> M)
    {
        for(int i = 1; i < N; i++){
            for(int j = 0; j < N; j++){
                int top = M[i-1][j];
                int topleft = (j == 0) ? 0 : M[i-1][j-1];
                int topright = (j == N - 1) ? 0 : M[i-1][j+1];
                M[i][j] += max({top, topleft, topright});
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++)
            ans = max(ans, M[N-1][i]);
        return ans;
    }
};
