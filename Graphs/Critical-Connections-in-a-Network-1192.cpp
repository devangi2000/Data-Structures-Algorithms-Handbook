// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections
//  forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi.
//  Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some
//  other server.
// Return all critical connections in the network in any order.

// Example 1:
// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.
// Example 2:

// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]] 

// Constraints:

// 2 <= n <= 105
// n - 1 <= connections.length <= 105
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated connections.

class Solution {
public:
    // initialize low time and in-time
    vector<int> in, low;
    vector<bool> visited;
    // make adjacency list of graph and result;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
    int timer = 0;
    
    void dfs(int current, int parent){
        in[current] = low[current] = ++timer;
        visited[current] = 1;
        for(int &child : edgeMap[current]){
            // don't do anything if the parent becomes the child
            if(parent == child) continue;
            // not visited child
            if(visited[child] == 0){
                dfs(child, current);
                low[current] = min(low[current], low[child]);
                if(low[child] > in[current])
                    ans.push_back({child, current});
            }
            // visited child
            else{
                low[current] = min(low[current], in[child]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        in.resize(n, 0);
        visited.resize(n, 0);
        low.resize(n, 0);
        for(auto &conn : connections){
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        for(int i = 0; i < n; i++)
            if(!visited[i])
                dfs(i, i);
        return ans;            
    }
};

