// Given a linked list, return the node where the cycle begins.
// If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in
// the list that can be reached again by continuously following 
// the next pointer. Internally, pos is used to denote the index of
// the node that tail's next pointer is connected to. Note that pos 
// is not passed as a parameter.

// Notice that you should not modify the linked list.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
// Example 2:
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
// Example 3:
// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.
 

// Constraints:

// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or head->next == NULL)
            return NULL;
        ListNode* fast = head, *slow = head, *entry = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;            
            if(slow == fast){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
