// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the
//  values of the nodes in the tree.

// Example 1:
// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:
// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

// Constraints:
// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104

// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the 
// kth smallest frequently, how would you optimize?

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
    vector<int> v;
    void solve(TreeNode *root, vector<int> &v)
    {
        if(root==NULL)return;
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root, v);
        return v[k-1];
    }
};

// Method 2

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(--k == 0) return root->val;
            else root = root->right;
        }
        return -1;
    }
};