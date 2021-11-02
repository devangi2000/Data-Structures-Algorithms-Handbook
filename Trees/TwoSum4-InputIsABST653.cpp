// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements
//  in the BST such that their sum is equal to the given target.

// Example 1:
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:
// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
// Example 3:
// Input: root = [2,1,3], k = 4
// Output: true
// Example 4:
// Input: root = [2,1,3], k = 1
// Output: false
// Example 5:
// Input: root = [2,1,3], k = 3
// Output: true

// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -104 <= Node.val <= 104
// root is guaranteed to be a valid binary search tree.
// -105 <= k <= 105

// METHOD 1

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
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        return solve(root, k);
    }
    bool solve(TreeNode* root, int k){
        if(!root) return false;
        if(s.count(k - root->val)) return true;
        s.insert(root->val);
        return solve(root->left, k) || solve(root->right, k);
    }
};


// METHOD 2

class Solution {
public:
    vector<int> inorder;
    bool findTarget(TreeNode* root, int k) {
        getInorder(root);
        int left = 0, right = inorder.size() - 1;
        while(left < right){
            int x = inorder[left] + inorder[right];
            if(x == k)
                return true;
            else if(x < k)
                left++;
            else right--;
        }
        return false;
    }
    void getInorder(TreeNode* root){
        if(!root) return;
        getInorder(root->left);
        inorder.push_back(root->val);
        getInorder(root->right);
        return;
    }
};


// METHOD 3

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root,  k);
    }
    
    bool dfs(TreeNode* root,  TreeNode* cur, int k){
        if(cur == NULL)return false;
        return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
    }
    
    bool search(TreeNode* root, TreeNode *cur, int value){
        if(root == NULL)return false;
        return (root->val == value) && (root != cur) 
            || (root->val < value) && search(root->right, cur, value) 
                || (root->val > value) && search(root->left, cur, value);
    }
};

// Method 4

// iterative traversal using 2 stacks
// similar to 2 pointer approach

bool findTarget(TreeNode *root, int target) {
    stack<TreeNode*> leftStack, rightStack;
    TreeNode *ptr = root; // maintain a copy of the root node
    // fill the leftStack
    while(ptr) {
        leftStack.push(ptr);
        ptr = ptr->left;
    }
    // fill the rightStack
    ptr = root;
    while(ptr) {
        rightStack.push(ptr);
        ptr = ptr->right;
    }
    // apply 2 pointer approach
    // edge case: root node is a part of 
    while(!leftStack.empty() && !rightStack.empty() && leftStack.top() != rightStack.top()) {
        // fetch the values from stack {cur_min, cur_max}
        TreeNode *left_node = leftStack.top();
        TreeNode *right_node = rightStack.top();

        // if the required pair is found
        if(left_node->val + right_node->val == k)
            return true;
        else if(left_node->val + right_node->val < k) {
            // increase the left pointer
            TreeNode *temp = leftStack.top();
            leftStack.pop();
            // move to the right and add the leftmost nodes in the stack
            temp = temp->right;
            while(temp) {
                leftStack.push(temp);
                temp = temp->left;
            }
        }
        else {
            // decrease the right pointer
            TreeNode *temp = rightStack.top();
            rightStack.pop();
            // move to the left and add the rightmost nodes in the stack
            temp = temp->left;
            while(temp) {
                rightStack.push(temp);
                temp = temp->right;
            }
        }
    }
    return false; // the pair is not found
}