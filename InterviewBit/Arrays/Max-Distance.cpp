// Problem Description
// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

// Input Format
// First and only argument is an integer array A.
// Output Format
// Return an integer denoting the maximum value of j - i;
// Example Input
// Input 1:

//  A = [3, 5, 4, 2]
// Example Output
// Output 1:
//  2


// Example Explanation
// Explanation 1:
//  Maximum value occurs for pair (3, 4).

int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int, int>> v;
    for(int i=0; i<A.size(); ++i)
        v.emplace_back(A[i], i);
    sort(v.begin(), v.end());
    int mini = INT_MAX, ans = INT_MIN;
    for(int i=0; i<v.size(); ++i){
        mini = min(mini, v[i].second);
        ans = max(ans, v[i].second - mini);
    }
    return ans;
}
