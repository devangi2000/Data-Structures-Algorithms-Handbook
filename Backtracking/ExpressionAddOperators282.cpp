// Given a string num that contains only digits and an integer target, return all possibilities
//  to add the binary operators '+', '-', or '*' between the digits of num so that the resultant
//   expression evaluates to the target value.
// Example 1:

// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Example 2:

// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Example 3:

// Input: num = "105", target = 5
// Output: ["1*0+5","10-5"]
// Example 4:

// Input: num = "00", target = 0
// Output: ["0*0","0+0","0-0"]
// Example 5:

// Input: num = "3456237490", target = 9191
// Output: [] 

// Constraints:
// 1 <= num.length <= 10
// num consists of only digits.
// -231 <= target <= 231 - 1

class Solution {
public:
    string s;
    int target;
    vector<string> ans;
    
    void backtrack(int i, const string &path, long resSoFar, long prevNum){
        if(i == s.length()){
            if(resSoFar == target)
                ans.push_back(path);
            return;
        }
        string numStr;
        long num = 0;
        for(int j = i; j < s.length(); j++){
            if(j > i and s[i] == '0') break; // Skip leading zero number
            numStr += s[j];
            num = num*10 + (s[j] - '0');
            if(i == 0)
                backtrack(j+1, path + numStr, num, num);
            else{
                backtrack(j+1, path + '+' + numStr, resSoFar + num, num);
                backtrack(j+1, path + '-' + numStr, resSoFar - num, -num);
                backtrack(j+1, path + '*' + numStr, resSoFar - prevNum + prevNum * num, prevNum * num);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        this->s = num;
        this->target = target;
        backtrack(0, "", 0, 0);
        return ans;
    }
};

