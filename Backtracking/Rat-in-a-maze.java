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


class Solution {
    
    public static void dfs(int[][] m, int[][] visited, String s, int n, int i, int j, ArrayList<String> ans){
        if(i == n-1 && j == n-1){
            ans.add(s);
            return;
        }
        if(i+1 < n && visited[i+1][j]==0 && m[i+1][j]==1){
            visited[i][j] = 1;
            dfs(m, visited, s + "D", n, i+1, j, ans);
            visited[i][j] = 0;
        }
        if(j-1 >= 0 && visited[i][j-1]==0 && m[i][j-1]==1){
            visited[i][j] = 1;
            dfs(m, visited, s + "L", n, i, j-1, ans);
            visited[i][j] = 0;
        }
        if(j+1 < n && visited[i][j+1]==0 && m[i][j+1]==1){
            visited[i][j] = 1;
            dfs(m, visited, s + "R", n, i, j+1, ans);
            visited[i][j] = 0;
        }
        if(i-1 >= 0 && visited[i-1][j]==0 && m[i-1][j]==1){
            visited[i][j] = 1;
            dfs(m, visited, s + "U", n, i-1, j, ans);
            visited[i][j] = 0;
        }
    }
    
    public static ArrayList<String> findPath(int[][] m, int n) {
        ArrayList<String> ans = new ArrayList<>();
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return ans;
        int[][] visited = new int[n][n];
        dfs(m, visited, "", n, 0, 0, ans);
        Collections.sort(ans);
        return ans;
    }
}