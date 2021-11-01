// Given a binary tree, find its height.


// Example 1:

// Input:
//      1
//     /  \
//    2    3
// Output: 2
// Example 2:

// Input:
//   2
//    \
//     1
//    /
//  3
// Output: 3   

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function height() which takes root node of the tree as input parameter and returns an integer denoting the height of the tree. If the tree is empty, return 0. 


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 <= Number of nodes <= 105
// 1 <= Data of a node <= 105

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    int height(struct Node* root){
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }
};
