// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
// horizontally or vertically neighboring. The same letter cell may not be used more than once.
// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
  
// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
  
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int row, int col){
        if(word.size() == 0)
            return true;
        if(row<0 || row>=board.size() || col < 0 || col>= board[0].size() || board[row][col] != word[0])
            return false;
        char ch = board[row][col];
        board[row][col] = '*';
        string s = word.substr(1);
        bool res = dfs(board, s, row+1, col) || dfs(board, s, row-1, col) || dfs(board, s, row, col+1) || dfs(board, s, row, col-1);
        board[row][col] = ch;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word){
        bool ans = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]) 
                    if(dfs(board, word, i, j))
                        return true;                
            }
        }
        return false;
    }
};
