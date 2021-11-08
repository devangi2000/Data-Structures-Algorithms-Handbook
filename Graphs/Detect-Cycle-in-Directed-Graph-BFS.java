// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?page=1&category[]=Graph&query=page1category[]Graph
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


class Solution {
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        int count = 0;
        int[] indegree = new int[V];
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < V; i++)
            for(int it : adj.get(i))
                indegree[it]++;
        for(int i = 0; i < V; i++)
            if(indegree[i] == 0)
                q.offer(i);
                
        while(!q.isEmpty()){
            int curr = q.poll();
            count++;
            for(int it : adj.get(curr)){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.offer(it);
            }
        }
        return count == V ? false : true;
    }
}