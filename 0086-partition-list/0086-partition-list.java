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
    // 1 2 4 3 5 2
    // 
    public ListNode partition(ListNode head, int x) {
        ListNode smallTail = new ListNode();
        ListNode smallHead = smallTail;
        ListNode greatTail = new ListNode();
        ListNode greatHead = greatTail;
        while(head!=null){
            if(head.val<x){
                smallTail.next = head;
                smallTail = smallTail.next;
            }
            else{
                greatTail.next = head;
                greatTail = greatTail.next;
            }
            head = head.next;
        }
        greatTail.next = null;
        smallTail.next = greatHead.next;
        return smallHead.next;
    }
}