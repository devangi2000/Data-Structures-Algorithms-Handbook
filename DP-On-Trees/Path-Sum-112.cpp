// Given the root of a binary tree and an integer targetSum, return true
// if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.

// Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// Output: true
// Example 2:
// Input: root = [1,2,3], targetSum = 5
// Output: false
// Example 3:
// Input: root = [1,2], targetSum = 0
// Output: false

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

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
    int target;
    bool flag=false;
    void findSum(TreeNode* root, int sum){
        if(!root) return;
        root->val += sum;
        if(!root->left && !root->right && root->val == target){
            flag = true;
            return;
        }
        findSum(root->left, root->val);
        findSum(root->right, root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        target = targetSum;
        findSum(root, 0);
        return flag;
    }
};
