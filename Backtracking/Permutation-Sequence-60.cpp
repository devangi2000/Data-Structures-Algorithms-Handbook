// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence. 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123" 

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!

class Solution {
public:
    // storing factorials of 0 through 9
    vector<int> perms = {1, 1, 2, 6, 24, 120, 720, 5040,40320,362880};
    string ans = "";
    vector<int> v; // v -> {1, 2, 3, 4...n}
        
    void solve(int n, int k){
        // single element left, append it to the ans
        if(n == 1){
            ans += to_string(v.back());
            return;
        }
        // Calculating the required index. Perms[n-1] means for n = 4, perms[3] = 6
        // 15/6 = 2 will be index for k = 15 and n = 4 so we need index perms[1]
        int index = (k / perms[n-1]);
        // NOTE: if k is a multiple of elements partition then it's an edge case and we decrement index by 1
        if(k % perms[n-1] == 0) index--;
        ans += to_string(v[index]); // add value to string
        v.erase(v.begin() + index); // remove element from array
        k -= perms[n-1]*index; // adjust value of k; k = 15 - 6*2 = 3.
        // Recursive call with n=n-1 as one element is added we need remaining
        solve(n-1, k);
    }
        
    string getPermutation(int n, int k){
       if(n == 1) return "1";        
       for(int i = 1; i <= n; i++) v.emplace_back(i);
       solve(n, k);
       return ans;
    }
};

	
