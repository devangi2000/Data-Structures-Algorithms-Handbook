// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?page=1&category[]=Graph&query=page1category[]Graph#
// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(vector<int>adj[], vector<int> &visited, int parent, int current){
        visited[current] = 1;
        for(auto ele:adj[current]){
            // not visited
            if(!visited[ele])
            {
                if(dfs(adj, visited, current, ele)) return true; // found a cycle; stop; return
             }
             // if visited, MAKE SURE IT'S NOT THE PARENT; coz parent won't make a cycle but other adj elements will
            else if(ele!=parent)
                return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	   // Code here
	   vector<int> visited(V,0);
	   for(int i=0; i<V; i++){
	       if(!visited[i]){
	           bool temp = dfs(adj, visited, -1, i);
	           if(temp) return true;
	       }
	   }
	   return false;
	}
};
