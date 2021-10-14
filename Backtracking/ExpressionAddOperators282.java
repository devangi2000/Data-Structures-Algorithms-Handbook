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
    List<String> ans = new ArrayList<>();
    String s;
    int target;
    
    public void backtrack(int i, String path, long resSoFar, long prevNum){
        if(i == s.length()){
            if(resSoFar == target)
                ans.add(path);
            return;
        }
        for(int j = i; j < s.length(); j++){
            if(j > i && s.charAt(i) == '0') break; // Skip leading zero number
            long num = Long.parseLong(s.substring(i, j+1));
            if(i == 0)
                backtrack(j+1, path + num, num, num); // First num, pick it without adding any operator!
            else{
                backtrack(j+1, path + "+" + num, resSoFar + num, num);
                backtrack(j+1, path + "-" + num, resSoFar - num, -num);
                backtrack(j+1, path + "*" + num, resSoFar - prevNum + prevNum * num, prevNum * num);
            }
        }
    }
    
    public List<String> addOperators(String num, int target) {
        this.s = num;
        this.target = target;
        backtrack(0, "", 0, 0);
        return ans;
    }
}
