// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways
//  to group numbers and operators. You may return the answer in any order.
// Example 1:
// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
 
// Constraints:
// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.
// All the integer values in the input expression are in the range [0, 99].

class Solution {
    public List<Integer> diffWaysToCompute(String exp) {
        List<Integer> result = new ArrayList<>();
        int n = exp.length();
        for(int i = 0; i < n; i++){
            char c = exp.charAt(i);
            if(c == '+' || c == '-' || c == '*'){
                List<Integer> left = diffWaysToCompute(exp.substring(0, i));
                List<Integer> right = diffWaysToCompute(exp.substring(i+1));
                for(int n1 : left){
                    for(int n2 : right){
                        if(c == '+')
                            result.add(n1 + n2);
                        else if(c == '-')
                            result.add(n1 - n2);
                        else
                            result.add(n1 * n2);
                    }
                }
            }
        }        
        if(result.size() == 0)
            result.add(Integer.valueOf(exp));
        return result;
    }
}