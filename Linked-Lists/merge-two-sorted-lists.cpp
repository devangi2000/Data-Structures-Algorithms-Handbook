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


// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* curr1 = l1, *curr2 = l2, *prev = result;
        while(curr1 && curr2){
            if(curr1->val > curr2->val){
                prev->next = curr2;
                prev = prev->next;
                curr2 = curr2->next;
            }            
            else {
                prev->next = curr1;
                prev = prev->next;
                curr1 = curr1->next;
            }            
        }
        
        if(curr1){
            prev->next = curr1;
        }
        
        if(curr2){
            prev->next = curr2;
        }
        prev = result->next;
        delete result;
        return prev;
    }
};
