// Given an m x n matrix board containing 'X' and 'O', capture all regions that are
// 4-directionally surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example 1:


// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Surrounded regions should not be on the border, which means that any 'O' on the
// border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected
// to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells
// connected horizontally or vertically.
// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

// MY PREFERRED METHOD
class Solution {
public:
    void mark(vector<vector<char>> &board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = '1';
        mark(board, i+1, j);
        mark(board, i-1, j);
        mark(board, i, j-1);
        mark(board, i, j+1);
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        int r = board.size(), c = board[0].size();
        for(int i = 0; i < r; i++){
           mark(board, i, 0);
           mark(board, i, c-1);
        }
        for(int i = 0; i < c; i++){
           mark(board, 0, i);
           mark(board, r-1, i);
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == '1')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

     

// APPROACH 2
class Solution {
public:
    bool seen;
    void dfs(vector<vector<char>>& board, int i, int j, int r, int c, vector<vector<bool>>& visited){
        if(i<0 ||  j<0 || i>r-1 || j>c-1 || board[i][j]=='X' || visited[i][j]) return;
            visited[i][j] = true;
        if(i<=0 ||  j<=0 || i>=r-1 || j>=c-1) 
            seen=true;
        dfs(board, i+1, j, r, c, visited);
        dfs(board, i-1, j, r, c, visited);
        dfs(board, i, j+1, r, c, visited);
        dfs(board, i, j-1, r, c, visited);
    }
    void mark(vector<vector<char>>& board, int i, int j, int r, int c){
        if(i<0 ||  j<0 || i>r-1 || j>c-1 || board[i][j]=='X') return;
        board[i][j] = 'X';
        mark(board, i+1, j, r, c);
        mark(board, i-1, j, r, c);
        mark(board, i, j+1, r, c);
        mark(board, i, j-1, r, c);
    }
    
    void solve(vector<vector<char>>& board) {
        int r=board.size(), c=board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for(int i=1; i<r-1; ++i){
            for(int j=1; j<c-1; ++j){
                if(board[i][j]=='O' && !visited[i][j]){
                    seen = false; // becomes true if it is found to be connected to a boundary O
                    dfs(board, i, j, r, c, visited);
                    if(seen==false)
                        mark(board, i, j, r, c);
                    seen = true;
                } 
            }
        }
    }
};

