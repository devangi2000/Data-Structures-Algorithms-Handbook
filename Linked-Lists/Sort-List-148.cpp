// Given the head of a linked list, return the list after sorting it in ascending order.
// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)? 

// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:
// Input: head = []
// Output: []

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105

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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* slow = head, *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        
        return merge(sortList(fast), sortList(head));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode sentinel(0);
        ListNode* curr = &sentinel;
        
        while(l1 and l2){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1)
            curr->next = l1;
        else 
            curr->next = l2;
        return sentinel.next;
    }
};

