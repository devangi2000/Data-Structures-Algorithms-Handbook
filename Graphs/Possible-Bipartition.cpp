// Given a set of n people (numbered 1, 2, ..., n), we would like to split everyone into two groups of any size.

// Each person may dislike some other people, and they should not go into the same group. 

// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

// Return true if and only if it is possible to split everyone into two groups in this way.

// Example 1:

// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
// Example 2:

// Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:

// Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false

// Time Complexity O(E+V)

class Solution {
public:
    bool isBipartite(vector<vector<int>> &adj, int n, int node, vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto ele: adj[curr]){
                if(color[ele]==color[curr])
                    return false;
                if(color[ele]==-1){
                    color[ele] = 1-color[curr];
                    q.push(ele);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0; i<dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> color(n+1, -1);
        for(int i=1; i<=n; i++)
            if(color[i]==-1)
                if(!isBipartite(adj, n, i, color))
                    return false;
        return true;
    }
};
