// The thief has found himself a new place for his thievery again. There is only one entrance to this area,
//  called root.
// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

// Example 1:
// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:
// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 104


// THIS GIVES TLE
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {    
    public int rob(TreeNode root) {
        if(root == null) return 0;
        if(root.left == null && root.right == null) return root.val;
        int left = 0, right = 0, subleft = 0, subright = 0;
        if(root.left != null){
            left = rob(root.left);
            subleft = rob(root.left.left) + rob(root.left.right);
        }
        if(root.right != null){
            right = rob(root.right);
            subright = rob(root.right.left) + rob(root.right.right);
        }
        return Math.max(left+right, root.val+subleft+subright);
    }
}


// OPTIMISED
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {    
    Map<TreeNode, Integer> mp = new HashMap<>();
    public int rob(TreeNode root) {
        if(root == null) 
            return 0;
        if(mp.containsKey(root)) 
            return mp.get(root);
        if(root.left == null && root.right == null) return root.val;
        int left = 0, right = 0, subleft = 0, subright = 0;
        if(root.left != null){
            left = rob(root.left);
            subleft = rob(root.left.left) + rob(root.left.right);
        }
        if(root.right != null){
            right = rob(root.right);
            subright = rob(root.right.left) + rob(root.right.right);
        }
        int ans = Math.max(left+right, root.val+subleft+subright);
        mp.put(root, ans);
        return ans;
    }
}
