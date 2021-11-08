// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?page=1&category[]=Graph&query=page1category[]Graph
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

class Solution {
    public boolean checkCycle(ArrayList<ArrayList<Integer>> adj, int curr, int[] visited, int[] path){
        visited[curr] = 1;
        path[curr] = 1;
        for(int node : adj.get(curr)){
            if(visited[node] == 0){
                if(checkCycle(adj, node, visited, path) == true) return true;
            }
            else if(path[node] == 1) return true;
        }
        path[curr] = 0;
        return false;
    }
    
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        int[] visited = new int[V];
        int[] path = new int[V];
        for(int i = 0; i < V; i++){
            if(visited[i] == 0)
                if(checkCycle(adj, i, visited, path) == true) return true;
        }
        return false;
    }
}