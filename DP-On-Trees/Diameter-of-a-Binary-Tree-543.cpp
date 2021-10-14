// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// Example 1:
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].
// Example 2:

// Input: root = [1,2]
// Output: 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int &res){
        // Base condition
        if(root == NULL)
            return 0;
        // Hypothesis
        int left = solve(root->left, res);
        int right  = solve(root->right, res);
        // Induction
        int temp = 1 + max(left, right);
        int ans = max(1 + left + right, temp);
        res = max(res, ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root){
        int res = INT_MIN;
        solve(root, res);
        return res-1;
    }
};
