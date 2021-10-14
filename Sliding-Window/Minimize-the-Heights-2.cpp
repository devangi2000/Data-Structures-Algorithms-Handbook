// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

// Example 1:

// Input:
// K = 2, N = 4
// Arr[] = {1, 5, 8, 10}
// Output:
// 5
// Explanation:
// The array can be modified as 
// {3, 3, 6, 8}. The difference between 
// the largest and the smallest is 8-3 = 5.
// Example 2:

// Input:
// K = 3, N = 5
// Arr[] = {3, 9, 12, 16, 20}
// Output:
// 11
// Explanation:
// The array can be modified as
// {6, 12, 9, 13, 17}. The difference between 
// the largest and the smallest is 17-6 = 11. 

// Expected Time Complexity: O(N*logN)
// Expected Auxiliary Space: O(N)

// Constraints
// 1 ≤ K ≤ 104
// 1 ≤ N ≤ 105
// 1 ≤ Arr[i] ≤ 105

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pair<int, int>> v;
        vector<int> visited(n);
        
        for(int i = 0; i < n; i++){
            if(arr[i] - k >= 0)
                v.emplace_back(arr[i] - k, i);
            v.emplace_back(arr[i] + k, i);
        }
        sort(v.begin(), v.end());
        int left = 0, right = 0, ele = 0;
        while(ele < n and right < v.size()){
            if(visited[v[right].second] == 0)
                ele++;
            visited[v[right].second]++;
            right++;
        }
        
        int ans = v[right - 1].first - v[left].first;
        while(right < v.size()){
            if(visited[v[left].second] == 1)
                ele--;
            visited[v[left].second]--;
            left++;
            
            while(ele < n and right < v.size()){
                if(visited[v[right].second] == 0)
                    ele++;
                visited[v[right].second]++;
                right++;
            }
            
            if(ele == n)
                ans = min(ans, v[right - 1].first - v[left].first);
            else
                break;
        }
        return ans;
    }
};
