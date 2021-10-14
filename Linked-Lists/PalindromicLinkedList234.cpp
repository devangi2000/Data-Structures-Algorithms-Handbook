// Given the head of a singly linked list, return true if it is a palindrome. 

// Example 1:
// Input: head = [1,2,2,1]
// Output: true
// Example 2:
// Input: head = [1,2]
// Output: false

// Constraints:
// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9

// Follow up: Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return true;
        ListNode* fast = head, *slow = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow){
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;
        ListNode* nxt = NULL;
        while(head){
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
};