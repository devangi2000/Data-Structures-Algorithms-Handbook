// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1. 

// Example 1:
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.

class Solution {
public:    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        if(mat.size() == 0) return mat;        
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        queue<pair<int, int>> q;
        for(int i=0; i<mat.size(); ++i){
            for(int j=0; j<mat[0].size(); ++j){
                if(mat[i][j] == 0)
                    q.emplace(i, j);
                else mat[i][j] = INT_MAX;
            }
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            for(auto dir:dirs){
                int newx = x + dir[0];
                int newy = y + dir[1];
                
                if(newx >=0 and newx < mat.size() and newy >=0 and newy < mat[0].size()){
                    if(mat[newx][newy] > mat[x][y] + 1){
                        mat[newx][newy] = mat[x][y] + 1;
                        q.emplace(newx, newy);
                    }
                }
            }
        }
        return mat;
    }
};
