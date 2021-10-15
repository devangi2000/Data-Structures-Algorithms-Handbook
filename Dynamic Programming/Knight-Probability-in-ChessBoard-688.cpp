// On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k
//  moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right 
// cell is (n - 1, n - 1).
// A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells 
// in a cardinal direction, then one cell in an orthogonal direction.
// Each time the knight is to move, it chooses one of eight possible moves uniformly at random 
// (even if the piece would go off the chessboard) and moves there.
// The knight continues moving until it has made exactly k moves or has moved off the chessboard.
// Return the probability that the knight remains on the board after it has stopped moving. 

// Example 1:
// Input: n = 3, k = 2, row = 0, column = 0
// Output: 0.06250
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.
// Example 2:
// Input: n = 1, k = 0, row = 0, column = 0
// Output: 1.00000
 
// Constraints:

// 1 <= n <= 25
// 0 <= k <= 100
// 0 <= row, column <= n

class Solution {
public:
    vector<vector<int>> moves = {{1,2}, {1, -2}, {-1, 2}, {-1, -2}, {2, -1}, {2,1}, {-2, 1},{-2, -1}};
    double knightProbability(int n, int k, int row, int col) {
        if(k == 0) return 1.0;
        int len = n;
        vector<vector<double>> parent(n, vector<double> (n, 0.0));
        vector<vector<double>> child(n, vector<double> (n, 0.0));
        parent[row][col] = 1.0;
        int dx, dy;
        for(int i = 0; i < k; i++){
            for(int p = 0; p < n; p++){
                for(int q = 0; q < n; q++){
                    double prob = parent[p][q] / 8.0;
                    for(auto move: moves){
                        dx = p + move[0];
                        dy = q + move[1];
                        
                        if(dx >= 0 and dx < n and dy >= 0 and dy < n)
                            child[dx][dy] += prob;
                    }
                }
            }
            parent = child;
            fill(child.begin(), child.end(), vector<double>(n, 0.0));
        }
        double total = 0.0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                total += parent[i][j];
        return total;
    }
};
