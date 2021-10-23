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

 // Using Extra Space
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

// No Extra Space

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
public class Solution {
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    if(l1 == null) return l2;
    if(l2 == null) return l1;
    ListNode t1 = l1;
    ListNode t2 = l2; 
    
    //whichever list is starting with least, make it t1;
    if(t1.val > t2.val) {
        ListNode temp = t1;
        t1 = t2;
        t2 = temp;
    }
    l1 = t1; //this is what you return eventually

    while(t1.next!=null && t2!=null) {
        if(t1.val <= t2.val && t1.next.val <= t2.val) {
            t1 = t1.next; // proceed if both are less.
        }else if (t1.val <= t2.val){
            // if t2.val comes in b/w, connect t2, 
            // and make t1.next as t2.
            ListNode temp = t2;
            t2 = t1.next;
            t1.next = temp;
        }
    }
    //If the first list reaches end, just connect to second list.
    if(t1.next == null) {
        t1.next = t2;
    }
    return l1;
}
}