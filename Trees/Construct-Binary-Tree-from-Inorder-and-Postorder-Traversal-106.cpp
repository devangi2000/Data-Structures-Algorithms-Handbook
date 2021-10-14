// Given two integer arrays inorder and postorder where inorder is the inorder traversal
// of a binary tree and postorder is the postorder traversal of the same tree, construct
// and return the binary tree. 

// Example 1:

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1] 

// Constraints:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.

// Postorder has the root in the end
// Start from the end of postorder & pick an element to create a node
// Decrement postorder index
// Search for the picked element's position in inorder 
// Call to build right subtree from inorder's (position+1 to n)
// Call to build left subtree from inorder's (0 to position-1)
// Return the node
class Solution {
public:
    unordered_map<int, int> m;    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx){
        if(start>end)
            return NULL;
        int mid = m[postorder[idx]];
        idx--;
        TreeNode* root = new TreeNode(inorder[mid]);        
        root->right = solve(inorder, postorder, mid+1, end, idx);
        root->left = solve(inorder, postorder, start,mid-1, idx);        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
        for(int i=0; i<inorder.size(); i++)
            m[inorder[i]] = i;
         return solve(inorder, postorder, 0, postorder.size()-1, idx);
    }
};
