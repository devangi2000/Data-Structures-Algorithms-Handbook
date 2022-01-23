// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

// O(n2)

class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &vis, int curr, int parent = -1){
        if(vis[curr]) return true;
        vis[curr] = true;
        for(auto child : graph[curr])
            if(child != parent and dfs(graph, vis, child, curr))
                return true;
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = size(edges);
        vector<vector<int>> graph(n + 1);
        vector<bool> vis(n + 1);
        for(auto &edge : edges){
            fill(begin(vis), end(vis), false);
            graph[edge[0]].push_back(edge[1]), graph[edge[1]].push_back(edge[0]);
            if(dfs(graph, vis, edge[0])) return edge;
        }
        return {};
    }
};

// DSUF

class Solution {
public:
    vector<int> parent, rank;
    void unite(int x, int y){
        int a = find(x), b = find(y);
        if(a == b)
            return;
        if(rank[a] > rank[b])
            parent[b] = a;
        else if(rank[b] > rank[a])
            parent[a] = b;
        else{
            rank[a]++;
            parent[a] = b;
        }
    }
    
    int find(int x){
        if(parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent = vector<int>(edges.size() + 1, -1);
        rank = vector<int>(edges.size() + 1, 1);
        for(auto &edge : edges){
            if(find(edge[0]) == find(edge[1]))
                return edge;
            else unite(edge[0], edge[1]);
        }
        return edges[0];
    }
};

