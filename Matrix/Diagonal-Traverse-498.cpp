// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

// Example 1:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:
// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4] 

// Constraints:
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105

// METHOD 1

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
        unordered_map<int,vector<int> > M;        
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[i].size(); ++j){
                M[i + j].push_back(matrix[i][j]);
            }
        }        
        for(auto &P : M)
        {
            if((P.first % 2) == 0)
            {
                reverse(P.second.begin(),P.second.end());
            }
        }        
        vector<int> Result;        
        if(matrix.empty())
        {
            return (Result);
        }
        
        for(int i = 0; i <= matrix.size() + matrix[0].size() - 2; ++i)
        {
            Result.insert(Result.end(),M[i].begin(),M[i].end());
        }        
        return (Result);
    }
};

// METHOD 2
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty()) return vector<int>();
        int n = mat.size(), m = mat[0].size(), row = 0, col = 0;
        vector<int> ans;
        bool up = true;
        while(row < n and col < m){
            if(up){
                while(row > 0 and col < m-1){
                    ans.push_back(mat[row--][col++]);
                }
                ans.push_back(mat[row][col]);
                if(col == m-1) row++;
                else col++;
            }
            else{
                while(col > 0 and row < n-1){
                    ans.push_back(mat[row++][col--]);
                }
                ans.push_back(mat[row][col]);
                if(row == n-1) col++;
                else row++;
            }
            up = !up;
        }
        return ans;
    }
};

