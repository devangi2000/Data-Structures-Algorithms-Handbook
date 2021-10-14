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
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null)
            return true;
        ListNode fast = head, slow = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = reverseList(slow.next);
        slow = slow.next;
        while(slow != null){
            if(head.val != slow.val)
                return false;
            head = head.next;
            slow = slow.next;
        }
        return true;
    }
    
    public ListNode reverseList(ListNode head){
        ListNode pre = null, nxt = null;
        while(head != null){
            nxt = head.next;
            head.next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
}