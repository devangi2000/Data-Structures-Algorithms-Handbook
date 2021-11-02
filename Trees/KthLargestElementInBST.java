// Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


// Example 1:

// Input:
//       4
//     /   \
//    2     9
// k = 2 
// Output: 4

// Example 2:

// Input:
//        9
//         \ 
//           10
// K = 1
// Output: 10

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.


// Expected Time Complexity: O(H + K).
// Expected Auxiliary Space: O(H)


// Constraints:
// 1 <= N <= 1000
// 1 <= K <= N

/*
class Node
{
    int data;
    Node left;
    Node right;
    Node(int data)
    {
        this.data = data;
        left=null;
        right=null;
    }
}
*/
class Solution
{
    // return the Kth largest element in the given BST rooted at 'root'
    public int kthLargest(Node root,int k)
    {
        Stack<Node> st = new Stack<>();
        while(root != null || !st.isEmpty()){
            while(root != null){
                st.push(root);
                root = root.right;
            }
            root = st.pop();
            if(--k == 0) return root.data;
            else root = root.left;
        }
        return -1;
    }
}