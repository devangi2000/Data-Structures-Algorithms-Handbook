// You are given two non-empty linked lists representing two non-negative integers. 
// The most significant digit comes first and each of their nodes contains a single digit.
//  Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself. 

// Example 1:
// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:
// Input: l1 = [0], l2 = [0]
// Output: [0]
// Constraints:
// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

// Follow up: Could you solve it without reversing the input lists?

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> st1 = new Stack<>();
        Stack<Integer> st2 = new Stack<>();
        while(l1 != null){
            st1.push(l1.val);
            l1 = l1.next;
        }
        while(l2 != null){
            st2.push(l2.val);
            l2 = l2.next;
        }
        int carry = 0;
        ListNode head = null;
        while(!st1.isEmpty() || !st2.isEmpty() || carry > 0){
            int sum = carry;
            if(st1.size() > 0)
                sum += st1.pop();
            if(st2.size() > 0)
                sum += st2.pop();
            ListNode node = new ListNode(sum % 10);
            node.next = head;
            head = node;
            
            carry = sum / 10;
        }
        return head;
    }
}