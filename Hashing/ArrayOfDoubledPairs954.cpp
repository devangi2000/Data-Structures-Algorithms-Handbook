// Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

 

// Example 1:

// Input: arr = [3,1,3,6]
// Output: false
// Example 2:

// Input: arr = [2,1,2,6]
// Output: false
// Example 3:

// Input: arr = [4,-2,2,-4]
// Output: true
// Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
// Example 4:

// Input: arr = [1,2,4,16,8,4]
// Output: false
 

// Constraints:

// 2 <= arr.length <= 3 * 104
// arr.length is even.
// -105 <= arr[i] <= 105


class Solution {
public:
    static bool compare(int a, int b){
        return abs(a) < abs(b);
    }
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> m;
        sort(begin(arr), end(arr), compare);
        for(int num : arr)
            m[num]++;
        for(int num : arr){
            if(m[num] == 0)
                continue;
            else if(m[2 * num] == 0)
                return false;
            else{
                m[num]--;
                m[2 * num]--;
            }
        }
        return true;
    }
};