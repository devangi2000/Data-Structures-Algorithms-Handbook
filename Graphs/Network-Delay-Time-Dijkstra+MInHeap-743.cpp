// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel
// times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node,
// and wi is the time it takes for a signal to travel from source to target.
// We will send a signal from a given node k. Return the time it takes for all the n nodes to receive
// the signal. If it is impossible for all the n nodes to receive the signal, return -1.

// Example 1:

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // pair of {time, node}
        vector<vector<pair<int,int>>> adj(n);
        for(auto time: times){
            // adj[u].push_back({cost, adj[v]})
            adj[time[0]-1].push_back({time[2], time[1]-1});
        }
        vector<int> dist(n, INT_MAX);
        // Min Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // push the starting node at 0
        pq.push({0, k-1});
        dist[k-1] = 0;        
        // Dijkstra's Algo
        while(!pq.empty()){
            int curr = pq.top().second; // take the next node
            pq.pop();
            for(auto a : adj[curr]){
                if(dist[curr] != INT_MAX and dist[curr] + a.first < dist[a.second]){
                    dist[a.second] = dist[curr] + a.first;
                    pq.push({dist[a.second], a.second});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<dist.size(); i++)
            ans = max(ans, dist[i]);
        
        return ans == INT_MAX? -1 : ans;
    }
};
