// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Example 1:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation: The graph is shown.
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
// Example 2:

// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation: The graph is shown.
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

// Constraints:

// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 104
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst

// DFS + Pruning that gives TLE
class Solution {
public:
    int fare = INT_MAX;    
    void solve(int amount, int src, int dst, int k, vector<vector<int>> &cost, vector<bool> &visited, vector<vector<int>> &adj){
        if(k<-1)
            return;
        if(src == dst){
            fare = min(fare, amount);
            return;
        }
        visited[src] = 1;
        for(auto a: adj[src]){
            if(!visited[a] && amount + cost[src][a] <= fare)
                solve(amount + cost[src][a], a, dst, k-1, cost, visited, adj);
        }
        visited[src] = false;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<int>> cost(n+1, vector<int>(n+1));
        vector<vector<int>> adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back(flights[i][1]);
            cost[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        vector<bool> visited(n+1, false);
        solve(0, src, dst, k, cost, visited, adj);        
        return fare == INT_MAX? -1 : fare;
    }
};

// DIJKSTRA + PRIORITY-QUEUE; WORKS AND NO TLE
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
       vector<vector<pair<int, int>>> g(n);
        for(auto x : flights)
            g[x[0]].push_back({x[1], x[2]});
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // minHeap
        // (cost, source, stops)
        pq.push({0, {src, -1}});
        vector<int> visited(n+1, INT_MAX);
        while(!pq.empty()){
            auto cost = pq.top().first;
            auto u = pq.top().second.first;
            auto stops = pq.top().second.second;
            pq.pop();
            if(visited[u] < stops) //if current node has been already visited with less steps then continue
                continue;
            visited[u] = stops;   //update the steps for the node
            if(u == dst) return cost;
            if(stops + 1 <= k){
            for(auto child : g[u]){
               pq.push({cost + child.second, {child.first, stops+1}});
            }
        }
     }
        return -1;
    }
};
