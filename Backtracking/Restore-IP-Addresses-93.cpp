// Given a string s containing only digits, return all possible
// valid IP addresses that can be obtained from s. You 
// can return them in any order.
// A valid IP address consists of exactly four integers,
// each integer is between 0 and 255, separated by single 
// dots and cannot have leading zeros. For example, "0.1.2.201" 
//   and "192.168.1.1" are valid IP addresses and "0.011.255.245", 
// "192.168.1.312" and "192.168@1.1" are invalid IP addresses.  

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "1111"
// Output: ["1.1.1.1"]
// Example 4:

// Input: s = "010010"
// Output: ["0.10.0.10","0.100.1.0"]
// Example 5:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"] 

// Constraints:

// 0 <= s.length <= 3000
// s consists of digits only.

class Solution {
public:
    vector<string> ans;
    void backtrack(string &s, int start, string path, int segment){
        if(segment == 4 and start == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < s.size(); ++i){
            if(segment < 4 and i - start < 3 and isValidIP(s, start, i)){
                path.append(s.substr(start, i-start+1));
                segment++;
                if(segment < 4) path+='.';
                backtrack(s, i+1, path, segment);
                if(segment < 4) path.pop_back();
                segment--;
                for(int j = 0; j < i - start + 1; j++) path.pop_back();
            }
        }
    }
    
    bool isValidIP(string s, int start, int end){
        string temp = s.substr(start, end - start + 1);
        int ip = stoll(temp);
        if(s[start] == '0' and start != end) return false;
        if(ip >= 0  and ip <= 255) return true;
        return false;
    }
    
    vector<string> restoreIpAddresses(string s){
        string path = "";
        backtrack(s, 0 , path, 0);
        return ans;
    }
};
