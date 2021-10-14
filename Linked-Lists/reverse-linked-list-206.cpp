
// Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* next, *prev = NULL, *current = head;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }    
        head = prev;
        return head;
    }
};

