// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
// Given a linked list of N nodes such that it may contain a loop.

// A loop here means that the last node of the link list is connected to the node at position X. If the link list does not have any loop, X=0.

// Remove the loop from the linked list, if it is present.  


// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output: 1
// Explanation: The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|    
// A loop is present. If you remove it 
// successfully, the answer will be 1. 

// Example 2:

// Input:
// N = 4
// value[] = {1,8,3,4}
// X = 0
// Output: 1
// Explanation: The Linked list does not 
// contains any loop. 


// Expected time complexity : O(N)
// Expected auxiliary space : O(1)

// Constraints:
// 1 ≤ N ≤ 104

class Solution
{
    public:
    void removeLoop(Node* head)
    {
        Node *fast = head, *slow = head;
        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(slow == head){
            while(fast->next != slow)
                fast = fast->next;
            fast->next = NULL;
        }
        else if(slow == fast){
            slow = head;
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
};
