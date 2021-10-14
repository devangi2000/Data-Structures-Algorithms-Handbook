// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7] 

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1, dir = 0;
        while(top<=bottom and left<=right){
            if(dir == 0){ // left to right
                for(int i=left; i<=right; i++)
                    ans.push_back(matrix[top][i]);
                top++;
            }
            else if(dir == 1){ // top to bottom
                for(int i=top; i<=bottom; i++)
                    ans.push_back(matrix[i][right]);
                right--;
            }
            else if(dir == 2){ // right to left
                for(int i=right; i>=left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            else if(dir == 3){
                for(int i=bottom; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};
