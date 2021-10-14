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
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> m;
        Node* curr = head;
        while(curr){
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr){
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};

https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)
// METHOD 2 - o(1) SPACE

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // STEP 1: PASS 1
        // Creating a copy (except random pointer) of each old node and insert it next to the old node it's copied from.
        // That is, it will create new alternative nodes which are a copy (except random pointer) of its previous node.
        Node* node=head;
        while(node){
            Node* temp=node->next;
            node->next=new Node(node->val);
            node->next->next=temp;
            node=temp;
        }
        
        // STEP 2: PASS 2
        // Now copy the random pointer (if exists) of the old nodes to their copy new nodes.
        node=head;
        while(node){
            if(node->random)
                node->next->random=node->random->next;
            node=node->next->next; // go to next old node
        }
        
        //STEP 3: PASS 3
        // Copy the alternative nodes into "ans" link list using the "helper" pointer along with restoring the old link list.
        Node* ans=new Node(0); // first node is a dummy node
        Node* helper=ans;
    
        while(head){
            // Copy the alternate added nodes from the old linklist
            helper->next=head->next;
            helper=helper->next;
            
            // Restoring the old linklist, by removing the alternative newly added nodes
            head->next=head->next->next;
            head=head->next; // go to next alternate node   
        }
        return ans->next; // Since first node is a dummy node
    }
};

