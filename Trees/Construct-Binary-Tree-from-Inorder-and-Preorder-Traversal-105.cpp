// Given two integer arrays preorder and inorder where preorder is the preorder traversal
// of a binary tree and inorder is the inorder traversal of the same tree, construct
// and return the binary tree.

// Example 1:

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.

class Solution {
public:
    int idx = 0;
    unordered_map<int, int> m;
    
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int start, int end){
        if(start>end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[idx++]);
        if(start == end) return root;
        int mid = m[root->val];
        root->left = solve(preorder, inorder, start, mid-1);
        root->right = solve(preorder, inorder, mid+1, end);
        return root;        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n = preorder.size();
        m.clear();
        for(int i=0; i<n; i++) 
            m[inorder[i]] = i;
        return solve(preorder, inorder, 0, n-1);
    }
};
