// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Implement KthLargest class:
// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Returns the element representing the kth largest element in the stream.

// Example 1:

// Input
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]

// Explanation
// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3);   // return 4
// kthLargest.add(5);   // return 5
// kthLargest.add(10);  // return 5
// kthLargest.add(9);   // return 8
// kthLargest.add(4);   // return 8
 

// Constraints:

// 1 <= k <= 104
// 0 <= nums.length <= 104
// -104 <= nums[i] <= 104
// -104 <= val <= 104
// At most 104 calls will be made to add.
// It is guaranteed that there will be at least k elements in the array when you search for the kth element.
// Method 1
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    int kv = 0;
    KthLargest(int k, vector<int>& nums) {
        kv = k;
        if(nums.size() == 0) return;
        for(auto num: nums){
            minHeap.push(num);
            if(minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > kv)
            minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Method 2

class MedianFinder {
public:
    priority_queue<long> maxHeap;
    priority_queue<long, vector<long>, greater<long>> minHeap;
    MedianFinder() {        
    }    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num) maxHeap.push(num);
        else minHeap.push(num);        
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) return maxHeap.empty() ? 0 : (maxHeap.top() + minHeap.top()) / 2.0;
        else return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};
