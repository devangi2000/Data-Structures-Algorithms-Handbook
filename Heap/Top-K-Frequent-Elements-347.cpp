// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
  
// APPROACH 1 : MY FAVORITE
class Solution {
public:  
    vector<int> topKFrequent(vector<int>& nums, int k){
        if(k == nums.size()) return nums;
        unordered_map<int, int> m;
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(auto a:nums)
            m[a]++;         
        for(auto it=m.begin(); it!=m.end(); it++){
            minHeap.push({it->second, it->first});
            if(minHeap.size() > k)
                minHeap.pop();
        }
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};

// APPROACH 2
class Solution {
public:
static bool comp(pair<int,int> &a,pair<int,int> &b ) 
    {
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        
        vector<pair<int,int>> A;
        for(auto& x:mp)
            A.push_back(x);
            
        sort(A.begin(),A.end(),comp);  //sort according to second element of the vector
        vector<int> v;
  
        for(int i=0;i<k;i++)
        {
            v.push_back(A[i].first);
        }
        return v;
    }
};
