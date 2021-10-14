// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k,
// return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

// Example 1:

// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted. 

// Constraints:

// 1 <= k <= points.length <= 104
// -104 < xi, yi < 104


// APPROACH 1
class Solution {
public:
    static bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b)
    {
        return a.second < b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<vector<int>, int> m;
        vector<vector<int>> ans;
        for(auto point:points)
        {
            int dist = (point[0]*point[0]) + (point[1]*point[1]);
            m[point] = dist;            
        }
        vector<pair<vector<int>, int>> v;
        for(auto a:m) v.push_back({a.first, a.second});
        sort(v.begin(), v.end(), cmp);
        for(int i=0; i<k; i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};

// APPROACH 2, no comparator function
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        map<pair<int,int>, int> m;
        for(auto point: points){
            int distance = (point[0]*point[0] + point[1]*point[1]);
            pair<int, int> p = {point[0], point[1]};
            maxHeap.push({distance, p});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }
        
        vector<vector<int>> result;
        while(!maxHeap.empty()){
            vector<int> v;
            v.push_back(maxHeap.top().second.first);
            v.push_back(maxHeap.top().second.second);
            maxHeap.pop();
            result.push_back(v);
        }
        return result;
    }
};
