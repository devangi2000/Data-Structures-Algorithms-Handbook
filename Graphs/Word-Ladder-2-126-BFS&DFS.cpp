// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
// --------------------------------------------------------------------------------------------------------------------------------------------------
// store only parent to child relation nodes in the adjacency list because if we take a jump then it should increase the depth to get the minimum
// depth from source to destination. Other paths will never give the minimum depth route
// Step 1: Form Special adjacency List using BFS
// Step 2: Perform DFS for all possible words from starting word using the Adjacency List 
// This DFS makes sure that we don't call the parents or the same level nodes
// TC: O(26*L*N + V*E)

class Solution {
public:
    vector<vector<string>> answer;
    void DFS(string beginWord, string &endWord, unordered_map<string, unordered_set<string>> &adj, vector<string> &path){
        path.push_back(beginWord);
        if(beginWord == endWord){
            answer.push_back(path);
            path.pop_back();
            return;
        }
        for(auto ele:adj[beginWord]){
            DFS(ele, endWord, adj, path);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string>> adj;
        unordered_map<string, int> visited;
        queue<string> q;
        visited[beginWord] = 0;
        q.push(beginWord);
        
        while(!q.empty()){
            string current = q.front();
            q.pop();
            string temp = current;
            for(int i=0; i<temp.size(); ++i){
                for(char c='a'; c<='z'; ++c){
                    if(temp[i] == c)
                        continue;
                    temp[i] = c;                    
                    if(wordSet.count(temp)>0){
                        if(visited.count(temp)==0){
                            visited[temp] = visited[current] + 1;
                            q.push(temp);
                            adj[current].insert(temp);
                        }
                        else if(visited[temp] == visited[current] + 1)
                            adj[current].insert(temp);
                    }
                }
                temp[i] = current[i];
            }
        }
        vector<string>path;
        DFS(beginWord, endWord, adj, path);
        return answer;
    }
};
