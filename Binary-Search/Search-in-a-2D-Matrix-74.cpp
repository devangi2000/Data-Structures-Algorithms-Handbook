// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 // Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

// Method 1

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size(), i = 0, j = cols-1;
        while(i < rows && j >= 0){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] < target)
                i++;
            else j--;
        }
        return false;
    }
};

// Method 2

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size(), start = 0, end = (rows * cols) - 1;
        while(start <= end){
            int mid = start + (end - start) / 2, mid_val = matrix[mid/cols][mid%cols];
            if(mid_val == target)
                return true;
            if(mid_val < target)
                start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};
