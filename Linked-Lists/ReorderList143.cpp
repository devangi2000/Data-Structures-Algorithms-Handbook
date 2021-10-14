// You are given the head of a singly linked-list. The list can be represented as:
// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 
// Constraints:
// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000

// STACK-BASED METHOD 

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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        curr = head;
        int n = st.size();
        if(n <= 2) return;
        ListNode *next;
        for(int i = 0; i < n/2; i++){
            next = curr->next; // next is 2
            curr->next = st.top(); // 1 -> 5
            st.pop();
            curr = curr->next; // curr is 5
            curr->next = next; // 5 -> 2
            curr = curr->next; // curr is 2
        }
        curr->next = nullptr;
    }
};

// REVERSE HALF THE LINKED LIST METHOD
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
    void reorderList(ListNode* head) {
        if(!head or !head->next) return;
        // Find the midpoint
        ListNode* slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse starting from the midpoint till the end
        ListNode* pre = nullptr, *curr = slow, *next;
        // say, list is initially 1, 2, 3 ,4
        while(curr){
            next = curr->next; // curr is 1, pre is null, next is 2
            curr->next = pre; // null <- 1
            pre = curr; // pre is 1;
            curr = next; // curr is 2
        }
        // pre points to the starting node now (technically the last node (5) because it has been reversed)
        ListNode *n1 = head, *n2 = pre;
        // list is 1-2-3-4-5; n1 is 1 and n2 is 5
        while(n2->next){
            ListNode* next = n1->next; // next is 2
            n1->next = n2; // 1->5
            n1 = next; // n1 is 2
            
            next = n2->next; // next is 4
            n2->next = n1; 
            n2 = next;
        }
    }
};
 