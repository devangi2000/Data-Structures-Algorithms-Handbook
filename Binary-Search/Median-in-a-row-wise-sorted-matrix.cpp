// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
// Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

// Example 1:

// Input:
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]

// Output: 5

// Explanation:
// Sorting matrix elements gives us 
// {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

// Example 2:

// Input:
// R = 3, C = 1
// M = [[1], [2], [3]]
// Output: 2

// Expected Time Complexity: O(32 * R * log(C))
// Expected Auxiliary Space: O(1)


// Constraints:
// 1<= R,C <=150
// 1<= matrix[i][j] <=2000

class Solution{   
public:
    int countSmallerThanOrEqualToMid(vector<int> &A, int mid){
        int low = 0, high = A.size() - 1;
        while(low <= high){
            int m = (low + high) >> 1;
            if(A[m] <= mid)
                low = m+1;
            else
                high = m-1;
        }
        return low;
    }

    int median(vector<vector<int>> &matrix, int r, int c){
        int low = 0, high = 1e9;
        while(low <= high){
            int mid = (low + high) >> 1;
            int count = 0;
            for(int i = 0; i < r; i++){
                count += countSmallerThanOrEqualToMid(matrix[i], mid);
            }
            if(count <= (r*c)/2)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
