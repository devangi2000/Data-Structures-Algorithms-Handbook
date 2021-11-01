// Given a Binary search tree and a value X,  the task is to complete the function which will return the floor of x.

// Note: Floor(X) is an element that is either equal to X or immediately smaller to X. If no such element exits return -1.

// Example 1:

// Input:
//        8
//      /  \
//     5    9
//    / \    \
//   2   6   10
// X = 3
// Output: 2
// Explanation: Floor of 3 in the given BST
// is 2
// Example 2:

// Input:
//        3
//      /   \
//     2     5
//         /  \
//        4    7
//       /
//      3
// X = 1
// Output: -1
// Explanation: No smaller element exits
// Your task:
// You don't need to worry about the insert function, just complete the function floor() which should return the floor of X. If no such element exits return -1.

// Expected Time Complexity: O(Height of the BST)
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <= X, Value of Node <= 106

class Sol {
    // Function to return the floor of given number in BST.
    int floor(Node root, int key) {
        int val = -1;
        while(root != null){
        if(root.data == key)
            return key;
        else if(root.data > key)
            root = root.left;
        else{
            val = root.data;
            root = root.right;
        }
    }
    return val;
    }
}