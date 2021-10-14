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

// STACK BASED METHOD

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        Stack<ListNode> st = new Stack<>();
        ListNode curr = head;
        while(curr != null){
            st.push(curr);
            curr = curr.next;
        }
        curr= head;
        int n = st.size();
        if(n <= 2) return;
        ListNode next;
        for(int i = 0; i < n/2; i++){
            next = curr.next; // next is 2;
            curr.next = st.pop(); // 1 -> 5
            curr = curr.next; // curr is 5
            curr.next = next; // 5 -> 2
            curr = curr.next; // curr is 2
        }
        curr.next = null;
    }
}

// METHOD 2

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return;
            
        //Find the middle of the list
        ListNode slow = head, fast = head;
        while(fast!= null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
        ListNode pre = null, curr = slow;
        while(curr != null){
            ListNode next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
        //Start reordering one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
        ListNode n1 = head, n2 = pre, next;
        while(n2.next != null){
            next = n1.next;
            n1.next = n2;
            n1 = next;
            
            next = n2.next;
            n2.next = n1;
            n2 = next;
        }
    }
}

