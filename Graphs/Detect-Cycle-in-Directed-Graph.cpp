// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?page=1&category[]=Graph&query=page1category[]Graph
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


class Solution
{
    public:
    bool dfs(vector<int> adj[], int current, vector<int> &visited, vector<int> &order){
        visited[current] = 1;
        order[current] = 1;
        for(ele: adj[current]){
            if(!visited[ele]){
                bool temp = dfs(adj, ele, visited, order);
                if(temp) return true;
            }
            else if(order[ele]) return true;
        }
        order[current] = 0;
        return false;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int> order(V,0);
        vector<int> visited(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool temp = dfs(adj, i, visited, order);
                if(temp == true)
                return true;
            }
        }
        return false;
	}
};
