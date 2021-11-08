// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?page=1&category[]=Graph&query=page1category[]Graph
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

class Solution {
  public:
    bool checkCycle(vector<int> adj[], int curr, vector<int> &visited, vector<int> &path){
        visited[curr] = 1;
        path[curr] = 1;
        for(int node: adj[curr]){
            if(!visited[node]){
                if(checkCycle(adj, node, visited, path)) return true;
            }
            else if(path[node]) return true;
        }
        path[curr] = 0;
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), path(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i])
                if(checkCycle(adj, i, visited, path))
                    return true;
        }
        return false;
    }
};