// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence. 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!

class Solution {
    public String getPermutation(int n, int k) {
        int[] fact = new int[n+1];
        fact[0] = 1;
        int f = 1;
        List<Integer> nums = new ArrayList<>();
        for(int i = 1; i <= n; i++){
            f *= i;
            fact[i] = f;
            nums.add(i);
        }
        k -= 1;
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= n; i++){
            int index = k/fact[n-i];
            sb.append(String.valueOf(nums.get(index)));
            nums.remove(index);
            k -= index*fact[n-i];
        }
        return sb.toString();
    }
}

