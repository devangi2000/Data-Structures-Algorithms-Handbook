// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6
 
// Example 2:
// Input : 
// N = 8
// A[] = {12, -1, -7, 8, -15, 30, 16, 28}
// K = 3
// Output :
// -1 -1 -7 -15 -15 0 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(K)

// Constraints:
// 1 <= N <= 105
// 1 <= A[i] <= 105
// 1 <= K <= N

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
           int start = 0, end = 0;
           vector<long long> ans;
           queue<long long> q;
           while(end<N){
                if(A[end]<0)
                    q.push(A[end]);
                if(end - start + 1 < K)
                   end++;
                else if(end - start + 1 >= K){
                    ans.push_back(q.empty() ? 0 : q.front());
                    if(q.front() == A[start])
                        q.pop();
                    start++; end++;               }
           }
           return ans;
 }
