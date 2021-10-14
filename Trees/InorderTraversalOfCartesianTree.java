// Given an inorder traversal of a cartesian tree, construct the tree.
//  Cartesian tree : is a heap ordered binary tree, where the root is greater than all 
// the elements in the subtree. 
//  Note: You may assume that duplicates do not exist in the tree. 
// Example :
// Input : [1 2 3]
// Return :   
//           3
//          /
//         2
//        /
//       1

/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class Solution {
    public TreeNode build(ArrayList<Integer> v, int start, int end){
        if(start > end) return null;
        int index = -1, maxi = Integer.MIN_VALUE;
        for(int i = start; i <= end; i++){
            if(maxi < v.get(i)){
                maxi = v.get(i);
                index = i;
            }
        }
        TreeNode root = new TreeNode(v.get(index));
        root.left = build(v, start, index - 1);
        root.right = build(v, index + 1, end);
        return root;
    }
    
    public TreeNode buildTree(ArrayList<Integer> v){
        if(v.size() == 0) return null;
        return build(v, 0, v.size()-1);
    }
}

