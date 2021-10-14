// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 
// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

class Solution {
public:
    vector<vector<int>> ans;
    queue<TreeNode*> q;
       vector<vector<int>> levelOrder(TreeNode* root){
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){               
           vector<int> v;
            int n = q.size();
           for(int i=0; i<n; i++){
             TreeNode* temp = q.front();
             q.pop();
             v.push_back(temp->val);
             if(temp->left) q.push(temp->left);
             if(temp->right) q.push(temp->right);
         }
     ans.push_back(v);   
   }
        return ans;
 }
};
