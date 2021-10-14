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
    public boolean dfs(char[][] board, String word, int i, int j){
        if(word.length() == 0) return true;
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] != word.charAt(0)) return false;
        char ch = board[i][j];
        board[i][j] = '*';
        String s = word.substring(1);
        boolean res = dfs(board, s, i+1, j) || dfs(board, s, i-1, j) || dfs(board, s, i, j+1) || dfs(board, s, i, j-1);
        board[i][j] = ch;
        return res;
    }
    
    public boolean exist(char[][] board, String word) {
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] == word.charAt(0))
                    if(dfs(board, word, i, j) == true)
                        return true;
            }
        }
        return false;
    }
}
