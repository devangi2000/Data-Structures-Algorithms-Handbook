// An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

// Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

 

// Example 1:

// Input: changed = [1,3,4,2,6,8]
// Output: [1,3,4]
// Explanation: One possible original array could be [1,3,4]:
// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.
// Other original arrays could be [4,3,1] or [3,1,4].
// Example 2:

// Input: changed = [6,3,0,1]
// Output: []
// Explanation: changed is not a doubled array.
// Example 3:

// Input: changed = [1]
// Output: []
// Explanation: changed is not a doubled array.
 

// Constraints:

// 1 <= changed.length <= 105
// 0 <= changed[i] <= 105


class Solution {
    public int[] findOriginalArray(int[] arr) {
        int n = arr.length;
        if(n % 2 != 0)return new int[0];
        
        int[] res = new int[n/2];
        int idx = 0;
        
        Arrays.sort(arr);
        int j = n-1;
        Map<Integer,Integer> map = new HashMap<>();
        
        while(j >= 0){
            int element = arr[j];
            int twice = element * 2;
            
            if(map.containsKey(twice)){
                if(map.get(twice) == 1)map.remove(twice);
                else map.put(twice,map.get(twice) - 1);
                res[idx++] = element;
            }else{
                map.put(element,map.getOrDefault(element,0) + 1);
            }
            j--;
        }
        
        return idx == n/2 ? res : new int[0];
    }
}