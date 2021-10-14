// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
// return the number of negative numbers in grid.

// Example 1:
// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:
// Input: grid = [[3,2],[1,0]]
// Output: 0
// Example 3:
// Input: grid = [[1,-1],[-1,-1]]
// Output: 3
// Example 4:
// Input: grid = [[-1]]
// Output: 1 

// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), r = n-1, c = 0, count = 0;
        while(r >= 0 and c < m){
            if(grid[r][c] < 0){
                --r;
                count += m - c;
            }
            else ++c;
        }
        return count;
    }
};