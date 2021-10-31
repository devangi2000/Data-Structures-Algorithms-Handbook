// Given the root of a binary tree, return the postorder traversal of its nodes' values.
// Example 1:


// Input: root = [1,null,2,3]
// Output: [3,2,1]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
// Example 4:


// Input: root = [1,2]
// Output: [2,1]
// Example 5:


// Input: root = [1,null,2]
// Output: [2,1]
 

// Constraints:

// The number of the nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 

// Follow up: Recursive solution is trivial, could you do it iteratively?

// Recursive

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
    List<Integer> postorder = new ArrayList<>();    
    public List<Integer> postorderTraversal(TreeNode root) {
        if(root == null) return postorder;
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        postorder.add(root.val);
        return postorder;
    }
}

// Iterative

class Solution {
    List<Integer> postorder = new ArrayList<>();
    Stack<TreeNode> st = new Stack<>();
    public List<Integer> postorderTraversal(TreeNode root) {
        if(root == null) return postorder;
        st.push(root);
        while(!st.isEmpty()){
            TreeNode curr = st.pop();
            postorder.add(curr.val);
            if(curr.left != null)
                st.push(curr.left);
            if(curr.right != null)
                st.push(curr.right);
        }
        Collections.reverse(postorder);
        return postorder;
    }
}