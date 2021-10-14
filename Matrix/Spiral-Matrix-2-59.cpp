// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:
// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 20

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,1));
        int top = 0, bottom = n-1, left = 0, right = n-1, ind = 0;
        while(top<=bottom and left<=right){
            for(int i=left; i<=right; i++)
                    res[top][i] = ++ind;
            top++;
 
            for(int i=top; i<=bottom; i++)
                    res[i][right] = ++ind;
            right--;

            for(int i=right; i>=left; i--)
                    res[bottom][i] = ++ind;
            bottom--;
            
            for(int i=bottom; i>=top; i--)
                   res[i][left] = ++ind;
            left++;
        }
        return res;
    }
};
