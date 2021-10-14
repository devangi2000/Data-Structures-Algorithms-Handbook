// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence
// has an edge connecting them. A node can only appear in the sequence at most once. Note that the
// path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any path.

// Example 1:
// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
// Example 2:
// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42. 

// Constraints:

// The number of nodes in the tree is in the range [1, 3 * 104].
// -1000 <= Node.val <= 1000

class Solution {
public:       
    int solve(TreeNode* root, int &res){
        if(!root)
            return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        
        int temp = max(max(l, r) + root->val, root->val);
        int temp2 = max(temp, root->val + l + r);
        res = max(temp2, res);
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};
