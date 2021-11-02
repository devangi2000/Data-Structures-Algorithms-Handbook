// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements
//  in the BST such that their sum is equal to the given target.

// Example 1:
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:
// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
// Example 3:
// Input: root = [2,1,3], k = 4
// Output: true
// Example 4:
// Input: root = [2,1,3], k = 1
// Output: false
// Example 5:
// Input: root = [2,1,3], k = 3
// Output: true

// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -104 <= Node.val <= 104
// root is guaranteed to be a valid binary search tree.
// -105 <= k <= 105


// METHOD 1
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
    HashSet<Integer> set = new HashSet<>();
    
    public boolean findTarget(TreeNode root, int k) {
        return solve(root, k);
    }
    
    public boolean solve(TreeNode root, int k){
        if(root == null) return false;
        if(set.contains(k - root.val)) return true;
        set.add(root.val);
        return solve(root.left, k) || solve(root.right, k);
    }
}


// METHOD 2

class Solution {
    List<Integer> inorder = new ArrayList<>();
    public boolean findTarget(TreeNode root, int k) {
        getInorder(root);
        int left = 0, right = inorder.size() - 1;
        while(left < right){
            int x = inorder.get(left) + inorder.get(right);
            if(x == k)
                return true;
            else if(x < k)
                left++;
            else right--;
        }
        return false;
    }
    
    public void getInorder(TreeNode root){
        if(root == null) return;
        getInorder(root.left);
        inorder.add(root.val);
        getInorder(root.right);
        return;
    }
}