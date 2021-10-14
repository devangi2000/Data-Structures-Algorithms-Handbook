// Given a binary tree, determine if it is height-balanced.
//  Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees 
// of every node never differ by more than 1. 
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

// Example :
// Input : 
//           1
//          / \
//         2   3

// Return : True or 1 

// Input 2 : 
//          3
//         /
//        2
//       /
//      1

// Return : False or 0 
//          Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
//          Difference = 2 > 1. 

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
    int height(TreeNode* root){
    if(!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        if(abs(height(root->left) - height(root->right)) > 1)
            return 0;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

