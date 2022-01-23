// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

class Solution {
    public boolean dfs(ArrayList<Integer>[] graph, boolean[] visited, int curr, int parent){
        if(visited[curr] == true) return true;
        visited[curr] = true;
        for(int child : graph[curr]){
            if(parent != child && dfs(graph, visited, child, curr) == true)
                return true;
        }
        return false;
    }
    
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        boolean[] visited = new boolean[n+1];
        for(int i = 0; i <= n; i++)
            graph[i] = new ArrayList<>();
        for(int[] edge : edges){
            Arrays.fill(visited, false);
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
            if(dfs(graph, visited, edge[0], edge[1]))
                return edge;
        }
        return edges[0];
    }
}

// DSUF

class Solution {
    public int[] parent;
    public int[] rank;
    int find(int x){
        if(parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a == b)
            return;
        if(rank[a] > rank[b])
            parent[b] = a;
        else if(rank[b] > rank[a])
            parent[a] = b;
        else{
            rank[a]++;
            parent[b] = a;
        }
    }
    
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        parent = new int[n+1];
        rank = new int[n+1];
        Arrays.fill(parent, -1);
        for(int[] edge : edges){
            if(find(edge[0]) == find(edge[1]))
                return edge;
            else unite(edge[0], edge[1]);
        }
        return edges[0];
    }
}