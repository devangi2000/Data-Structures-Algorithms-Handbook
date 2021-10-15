// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 

// Constraints:

// 1 <= numRows <= 30

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int dp[numRows][numRows];
        for(int i=0; i<numRows; i++){
            vector<int> row;
            for(int j=0; j<=i; j++){
                if(j==0 || j==i)
                    dp[i][j] = 1;
                else if(i>0 and j>0){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                row.push_back(dp[i][j]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
