// Given the root of a binary tree, return the sum of all left leaves.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Example 2:
// Input: root = [1]
// Output: 0 

// Constraints:
// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000

// Method 1

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left and !root->left->left and !root->left->right) 
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
    }
};

// Method 2

class Solution {
public:
    int res = 0;
    
    void dfs(TreeNode* root, int direction){
        if(!root) return;
        if(!root->left and !root->right){
            if(direction == 0)
                res += root->val;
        }
        dfs(root->left, 0);
        dfs(root->right, 1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        dfs(root, -1);
        return res;
    }
};
