// Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

// Example 1:

// Input :
//                  4
//                /   \
//               2     6
//             /  \   /  \
//            1   3  5    7  

// Output : 1 2 3 4 5 6 7 
// Exaplanation :
//                7
//              /   \
//             3     6
//           /   \  /   \
//          1    2 4     5
// The given BST has been transformed into a
// Max Heap and it's postorder traversal is
// 1 2 3 4 5 6 7.
// Your task :
// You don't need to read input or print anything. Your task is to complete the function convertToMaxHeapUtil() which takes the root of the tree as input and converts the BST to max heap.
// Note : The driver code prints the postorder traversal of the converted BST.
 
// Expected Time Complexity : O(n)
// Expected Auxiliary Space : O(n)
 
// Constraints :
// 1 ≤ n ≤ 105

class Solution{
  public:
    void inorder(Node* root, vector<int> &arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    void BSTToMaxHeap(Node* root, vector<int> &arr, int *i){
        if(!root) return;
        BSTToMaxHeap(root->left, arr, i);
        BSTToMaxHeap(root->right, arr, i);
        root->data = arr[++*i];
    }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> arr;
        int i = -1;
        inorder(root, arr);
        BSTToMaxHeap(root, arr, &i);
    }    
};