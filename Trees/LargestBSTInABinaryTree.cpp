// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

// Example 1:

// Input:
//         1
//       /   \
//      4     4
//    /   \
//   6     8
// Output: 1
// Explanation: There's no sub-tree with size
// greater than 1 which forms a BST. All the
// leaf Nodes are the BSTs with size equal
// to 1.
// Example 2:

// Input: 6 6 3 N 2 9 3 N 8 8 2
//             6
//         /       \
//        6         3
//         \      /   \
//          2    9     3
//           \  /  \
//           8 8    2 
// Output: 2
// Explanation: The following sub-tree is a
// BST of size 2: 
//        2
//     /    \ 
//    N      8
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 106
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    vector<int> solve(Node *root){
        if(!root) return {1, 0, INT_MAX, INT_MIN};
        if(!root->left and !root->right) return {1, 1, root->data, root->data};
        
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        if(l[0] and r[0]){
            if(root->data > l[3] and root->data < r[2]){
                int x = l[2], y = r[3];
                if(x == INT_MAX) x = root->data;
                if(y == INT_MIN) y = root->data;
                return {1, l[1] + r[1] + 1, x, y};
            }
        }
        return {0, max(l[1], r[1]), 0, 0};
    }
    
    int largestBst(Node *root)
    {
    	vector<int> ans = solve(root);
    	return ans[1];
    }
};