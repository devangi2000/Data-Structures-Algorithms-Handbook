// Given the head of a sorted linked list, delete all nodes that have
// duplicate numbers, leaving only distinct numbers from the original
// list. Return the linked list sorted as well. 

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]
 
// Constraints:
// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* sentinel = new ListNode(0, head), *prev = sentinel;
        while(head){
            if(head->next and head->val == head->next->val){
                while(head->next and head->val == head->next->val){
                    head = head->next;
            }
               prev->next = head->next;
          }
            else{
                prev = prev->next;                
            }
            head = head->next;
        }
        return sentinel->next;
    }
};
