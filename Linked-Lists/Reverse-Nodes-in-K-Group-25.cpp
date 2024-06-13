// Given a linked list, reverse the nodes of a linked list k at
//  a time and return its modified list.
// k is a positive integer and is less than or equal to the 
// length of the linked list. If the number of nodes is not a 
// multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves
//  may be changed. 

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
// Example 3:

// Input: head = [1,2,3,4,5], k = 1
// Output: [1,2,3,4,5]
// Example 4:

// Input: head = [1], k = 1
// Output: [1] 

// Constraints:

// The number of nodes in the list is in the range sz.
// 1 <= sz <= 5000
// 0 <= Node.val <= 1000
// 1 <= k <= sz

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL or head->next == NULL or k == 1) return head;
        ListNode* sentinel = new ListNode(0, head);
        ListNode *curr = sentinel, *nxt = sentinel, *pre = sentinel;
        int len = 0;
        while(curr->next){
            curr = curr->next;
            len++;
        }
        
        while(len >= k){
            curr = pre->next;
            nxt = curr->next;
            for(int i = 1; i < k; ++i){
                curr->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = curr->next;
            }
            pre = curr;
            len-=k;
        }
        return sentinel->next;
    }
};


// Method 2

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
    void reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return;
        ListNode *prev = NULL, *curr = head;
        while(curr){
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return;
    }

    ListNode* getKthNode(ListNode* node, int k){
        k -= 1;
        while(node != nullptr && k>0){
            k--;
            node = node->next;
        }
        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *prevLast = nullptr;
        while(temp != nullptr) {
            ListNode *kthNode = getKthNode(temp, k);
            if(kthNode == nullptr) {
                if(prevLast) {
                    prevLast->next = temp;
                }
                break;
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseLL(temp);
            if( temp == head ) {
                head = kthNode;
            } else {
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
