// Given the root of a binary tree, return the zigzag level order traversal of its nodes'
//   values. (i.e., from left to right, then right to left for the next level and alternate between). 

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []

// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100

class Solution {
public:
    vector<vector<int>> v;
    queue<TreeNode*> q;
    int level=0;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       if(!root)
           return v;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(level%2)
                reverse(temp.begin(), temp.end());
            level++;
            v.push_back(temp);
        }
        return v;
    }
};
