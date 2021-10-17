// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together
//  the nodes of the first two lists.
// Example 1:
// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:
// Input: l1 = [], l2 = []
// Output: []
// Example 3:
// Input: l1 = [], l2 = [0]
// Output: [0] 

// Constraints:
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both l1 and l2 are sorted in non-decreasing order.

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode start = new ListNode(0);
        ListNode curr1 = l1, curr2 = l2, prev = start;
        while(curr1 != null && curr2 != null){
            if(curr1.val > curr2.val){
                prev.next = curr2;
                prev = prev.next;
                curr2 = curr2.next;
            }
            else{
                prev.next = curr1;
                prev = prev.next;
                curr1 = curr1.next;
            }
        }
        while(curr1 != null){
            prev.next = curr1;
            prev = prev.next;
            curr1 = curr1.next;
        }
        while(curr2 != null){
            prev.next = curr2;
            prev = prev.next;
            curr2 = curr2.next;
        }
        return start.next;
    }
}