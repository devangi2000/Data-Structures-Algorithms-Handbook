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
    public String largestNumber(int[] nums) {
        if(nums.length == 0) return "";
        String[] arr = new String[nums.length];
        for(int i = 0; i < nums.length; i++)
            arr[i] = String.valueOf(nums[i]);
        Comparator<String> comp = new Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                String a = s1 + s2;
                String b = s2 + s1;
                return b.compareTo(a);
            }
        };
        
        Arrays.sort(arr, comp);
        if(arr[0].charAt(0) == '0') return "0";
        StringBuilder sb = new StringBuilder();
        for(String s : arr)
            sb.append(s);
        return sb.toString();
    }
};


