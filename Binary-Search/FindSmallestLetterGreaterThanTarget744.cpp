Given a characters array letters that is sorted in non-decreasing order and a character target,
//  return the smallest character in the array that is larger than target.
// Note that the letters wrap around.
// For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.

// Example 1:
// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Example 2:
// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Example 3:
// Input: letters = ["c","f","j"], target = "d"
// Output: "f"
// Example 4:
// Input: letters = ["c","f","j"], target = "g"
// Output: "j"
// Example 5:
// Input: letters = ["c","f","j"], target = "j"
// Output: "c" 

// Constraints:
// 2 <= letters.length <= 104
// letters[i] is a lowercase English letter.
// letters is sorted in non-decreasing order.
// letters contains at least two different characters.
// target is a lowercase English letter.

// METHOD 1

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char c: letters)
            if(c > target)
                return c;
        return letters[0];
    }
};
// METHOD 2

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size();
        while(low < high){
            int mid = low + (high - low) / 2;
            if(letters[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }
        return letters[low % letters.size()];
    }
};