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
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int num : arr)
            mp.put(num, mp.getOrDefault(num , 0) + 1);
        Integer[] copy_a = new Integer[arr.length];
        for(int i = 0; i < arr.length; i++)
            copy_a[i] = arr[i];
        Arrays.sort(copy_a, Comparator.comparingInt(Math::abs));
        for(int num : copy_a){
            if(mp.get(num) == 0)
                continue;
            if(mp.getOrDefault(2 * num, 0) <= 0)
                return false;
            mp.put(num, mp.get(num) - 1);
            mp.put(2 * num, mp.get(2 * num) - 1);
        }
        return true;
    }
}