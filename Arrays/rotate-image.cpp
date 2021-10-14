// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]


class Solution {
public:
    void rotate(vector<vector<int>>& A) {
       for(int i=0; i<A.size(); i++)
       {
           for(int j=0; j<i; j++)
           {
              swap(A[i][j], A[j][i]);
           }  
       }
        for(int i=0; i<A.size(); i++)
       reverse(A[i].begin(), A[i].end());
    }
};

