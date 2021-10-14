// Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

// Example 1:

// Input:
//    1
//  /  \
// 3    2
// Output: 1 3

// Example 2:

// Input:

// Output: 10 20 40
// Your Task:
// You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 0 <= Number of nodes <= 100
// 1 <= Data of a node <= 1000

// ITERATIVE
vector<int> ans;
void solve(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1; i<=n; i++){
            Node* temp = q.front();
            q.pop();
            if(i==1)
                ans.push_back(temp->data);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   if(root == NULL) return ans;
   solve(root);
   return ans;
}


// RECURSIVE

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void leftView(TreeNode* root, vector<int> &ans, int n){
    if(!root) return;
    if(ans.size() == n)
        ans.push_back(root->val);
    leftView(root->left, ans, n+1);     
    leftView(root->right, ans, n+1);
} 
 
vector<int> Solution::solve(TreeNode* root) {
    vector<int> ans;
    leftView(root, ans, 0);
    return ans;
}
