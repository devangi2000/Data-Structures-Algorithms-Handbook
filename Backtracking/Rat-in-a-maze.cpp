// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1).
// Find all possible paths that the rat can take to reach from source to destination
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
// Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.

// Expected Time Complexity: O((N2)4).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

// Constraints:
// 2 ≤ N ≤ 5
// 0 ≤ m[i][j] ≤ 1

class Solution{
    public:
    vector<string> v;
    string s="";
        
    void dfs(int i, int j, vector<vector<int>> &m, string s, int n, vector<vector<int>> &visited){
        // base condition
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0 || visited[i][j]==1) return;
        // found the end
        if(i==n-1 and j==n-1){
            v.push_back(s);
            return;
        }
        visited[i][j] = 1;
        dfs(i+1, j, m, s+'D', n, visited);
        dfs(i-1, j, m, s+'U', n, visited);
        dfs(i, j+1, m, s+'R', n, visited);
        dfs(i, j-1, m, s+'L', n, visited);
        visited[i][j] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0 || m[n-1][n-1]==0) return v;
        vector<vector<int>> visited(m.size(), vector<int>(m[0].size()));
        dfs(0, 0, m, s, n, visited);
        sort(v.begin(), v.end());
        return v;
    }
};
