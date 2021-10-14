// Given an m x n board of characters and a list of strings words,
//  return all words on the board.
// Each word must be constructed from letters of sequentially adjacent
//  cells, where adjacent cells are horizontally or vertically neighboring.
//  The same letter cell may not be used more than once in a word. 

// Example 1:
// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:
// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 // Constraints:
// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.

class Solution {
public:
    struct TrieNode{
        char c;
        int endsHere;
        string word;
        TrieNode *children[26];
    };
    
    struct TrieNode *getNode(char c){
        TrieNode *newnode = new TrieNode;
        newnode->c = c;
        newnode->endsHere = 0;
        newnode->word = "";
        for(int i = 0; i < 26; i++)
            newnode->children[i] = NULL;
        return newnode;
    };
    
    TrieNode *root = getNode('/');
    
    void insert(string s){
        TrieNode *curr = root;
        for(int i = 0; i < s.size(); i++){
            int index = s[i] - 'a';
            if(curr->children[index] == NULL)
                curr->children[index] = getNode(s[i]);
            curr = curr->children[index];
        }
        curr->endsHere += 1;
        curr->word = s;
    }
    
    void solve(vector<vector<char>> &board, int i, int j, int r, int c, vector<string> &ans, TrieNode *curr){
        // BASE: If the trie doesn't have the current char or cell is visited           
        int index = board[i][j] - 'a';
        if(board[i][j] == '#' or curr->children[index] == NULL)
            return;
        curr = curr->children[index];
        if(curr->endsHere > 0){
            ans.push_back(curr->word);
            curr->endsHere = -1;
        }
        char ch = board[i][j];
        board[i][j] = '#';
        if(i>0) solve(board, i-1, j, r, c, ans, curr);
        if(j>0) solve(board, i, j-1, r, c, ans, curr);
        if(i<r-1) solve(board, i+1, j, r, c, ans, curr);
        if(j<c-1) solve(board, i, j+1, r, c, ans, curr);
        board[i][j] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int r = board.size(), c = board[0].size();
        // Insert all nodes in Trie
        for(int i = 0; i < words.size(); i++)
            insert(words[i]);
        vector<string> ans;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                solve(board, i, j, r, c, ans, root);
        return ans;
    }
};