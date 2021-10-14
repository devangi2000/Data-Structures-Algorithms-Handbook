// Given an inorder traversal of a cartesian tree, construct the tree.
//  Cartesian tree : is a heap ordered binary tree, where the root is greater than 
// all the elements in the subtree. 
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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(vector<int> &v, int start, int end){
    if(start > end) return nullptr;
    int maxi = INT_MIN; int index = -1;
    for(int i = start; i <= end; i++){
        if(maxi < v[i]){
            maxi = v[i];
            index = i;
        }
    }
    TreeNode* root = new TreeNode(v[index]);
    root->left = build(v, start, index-1);
    root->right = build(v, index+1, end);
    return root;
} 
 
TreeNode* Solution::buildTree(vector<int> &v){
    if(v.size() == 0) return nullptr;
    return build(v, 0, v.size()-1);
}
