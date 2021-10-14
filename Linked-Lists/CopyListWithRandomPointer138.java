// A linked list of length n is given such that each node contains an additional random pointer, 
// which could point to any node in the list, or null.
// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes,
//  where each new node has its value set to the value of its corresponding original node. Both the 
// next and random pointer of the new nodes should point to new nodes in the copied list such that 
// the pointers in the original list and copied list represent the same list state. None of the pointers
//  in the new list should point to nodes in the original list.
// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding
//  two nodes x and y in the copied list, x.random --> y.
// Return the head of the copied linked list.
// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

// Example 1:
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Example 2:
// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
// Example 3:
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]
// Example 4:
// Input: head = []
// Output: []
// Explanation: The given linked list is empty (null pointer), so return null.
// Constraints:
// 0 <= n <= 1000
// -10000 <= Node.val <= 10000
// Node.random is null or is pointing to some node in the linked list.

// METHOD 1 - BRUTE FORCE
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        Node curr = head;
        Map<Node, Node> mp = new HashMap<>();
        while(curr != null){
            mp.put(curr, new Node(curr.val));
            curr = curr.next;
        }
        curr = head;
        while(curr != null){
            mp.get(curr).next = mp.get(curr.next);
            mp.get(curr).random = mp.get(curr.random);
            curr = curr.next;
        }
        return mp.get(head);
    }
}
// https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)
// METHOD 2:

/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if( head == null) return head;
        Node cur = head;
        while(cur != null){
            Node temp = cur.next;
            cur.next = new Node(cur.val);
            cur.next.next = temp;
            cur=temp;
        }
        
        cur = head;
        
        while(cur != null){
            if(cur.next != null){
                cur.next.random = cur.random != null ?cur.random.next : null;
            }
            cur = cur.next.next;
        }
        Node dummy = head,copy = head.next;
        Node temp = copy;
        while(dummy != null){
            dummy.next = dummy.next.next;
            copy.next = copy.next != null ? copy.next.next: null;
            dummy = dummy.next;
            copy = copy.next;
        }
       return temp; 
    }
}
