// Given a list of non-negative integers nums, arrange them such that they form the largest number.
// Note: The result may be very large, so you need to return a string instead of an integer. 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
// Example 3:

// Input: nums = [1]
// Output: "1"
// Example 4:

// Input: nums = [10]
// Output: "10" 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109

class Solution {
public:
    static bool compare(string a, string b){
        return b+a < a+b;
    }
    string largestNumber(vector<int>& nums){
        vector<string> v;
        for(auto num : nums)
            v.push_back(to_string(num));
        sort(v.begin(), v.end(), compare);
        string res = "";
        for(auto num: v)
            res += num;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
    }
};