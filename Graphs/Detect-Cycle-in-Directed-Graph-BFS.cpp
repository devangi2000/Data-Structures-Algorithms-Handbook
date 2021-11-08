// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?page=1&category[]=Graph&query=page1category[]Graph
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++)
            for(auto it : adj[i])
                indegree[it]++;
        for(int i = 0; i < V; i++)
            if(indegree[i] == 0)
                q.push(i);
        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count++;
            for(int it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return count != V;
    }
};