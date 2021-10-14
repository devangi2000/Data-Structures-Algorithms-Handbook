// The median is the middle value in an ordered integer list. If the size of the list is even,
//  there is no middle value and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
 
// Constraints:

// -105 <= num <= 105
// There will be at least one element in the data structure before calling findMedian.
// At most 5 * 104 calls will be made to addNum and findMedian.
 

// Follow up:

// If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
// If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?


// This is the Priority queue method so TC is O(NlogN)
class MedianFinder {
public:
    priority_queue<long> maxHeap;
    priority_queue<long, vector<long>, greater<long>> minHeap;
    
    MedianFinder() {
        
    }

      void addNum(int num){
        if(maxHeap.size() == minHeap.size()){
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else{
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        int maxHeapSize = maxHeap.size(), minHeapSize = minHeap.size();
        if(maxHeapSize > minHeapSize)
            return (double)(maxHeap.top());
        return (double(maxHeap.top() + minHeap.top()))/2.0;        
    }
};


// This addNum Function may be more readable but it has some error that I can't find out

// void addNum(int num) {
    //     long maxHeapSize = maxHeap.size(), minHeapSize = minHeap.size();
    //     if(maxHeap.empty())
    //         maxHeap.push(num);
    //     else if(maxHeapSize == minHeapSize){
    //         if(maxHeap.top() > num)
    //             maxHeap.push(num);
    //         else
    //         {
    //             long temp = minHeap.top();
    //             minHeap.pop();
    //             maxHeap.push(temp);
    //             minHeap.push(num);
    //         }
    //     }
    //     else{
    //         if(minHeap.empty()){
    //             if(maxHeap.top() < num)
    //                 minHeap.push(num);
    //             else {
    //                 long temp = maxHeap.top();
    //                 maxHeap.pop();
    //                 minHeap.push(temp);
    //                 maxHeap.push(num);
    //             }
    //         }
    //         else if(num >= minHeap.top())
    //             minHeap.push(num);
    //         else{
    //             if(num < maxHeap.top()){
    //                 long temp = maxHeap.top();
    //                 maxHeap.pop();
    //                 minHeap.push(temp);
    //                 maxHeap.push(num);
    //             }
    //             else
    //                 minHeap.push(num);
    //         }
    //     }
    // }

    // //Approach-2 (O(n^2) - Insertion Sort)
class MedianFinder {
public:
    vector<int> vec;
    int i = 0;
    MedianFinder() {
        vec.resize(5*10000+1);
    }
    
    void addNum(int num) {
        if(i == 0) {
            vec[i++] = num;
            return;
        }
        int j = i-1;
        while(j >= 0 && vec[j] > num) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = num;
        i++;
    }
    
    double findMedian() {
        int n = i;
        if(n%2 == 0) {
            int l = n/2-1;
            int r = n/2;
            return (float)(vec[l]+vec[r])/2;
        }
        
        return vec[n/2];
    }
};