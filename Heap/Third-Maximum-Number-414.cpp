// Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.

// Example 1:

// Input: nums = [3,2,1]
// Output: 1
// Explanation: The third maximum is 1.
// Example 2:

// Input: nums = [1,2]
// Output: 2
// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:

// Input: nums = [2,2,3,1]
// Output: 1
// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.
 

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1
  
// Stupid Approach using N(log(N)) approach is sorting. Not doing it. Nah.
// APPROACH 1: using Max Heap
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq;
        unordered_map<int,int> m;
        for( auto a: nums)
        {
            if(m[a]==0)
            {m[a]++;
            pq.push(a);}
        }
        if(pq.size()<3)return pq.top();
        int i=0;
        while(i++ <2)
        {
            pq.pop();
        }
        return pq.top();
    }
};

// APPROACH 2: Min Heap
class Solution {
public:
    int thirdMax(vector<int>& arr) 
    {
        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto a:arr){
            if(m[a] == 0){
                m[a]++;
                minHeap.push(a);
            }
            if(minHeap.size() > 3){
                int x = minHeap.top();
                minHeap.pop();
                m[x]--;
            }                
        }
        if(minHeap.size() == 3) return minHeap.top();
        else{
            while(minHeap.size() != 1)
                minHeap.pop();
        }
        return minHeap.top();
    }
};
