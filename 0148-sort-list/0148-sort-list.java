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
    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
    private ListNode getMiddle(ListNode node){
        if(node==null) return node;
        ListNode fast=node;
        ListNode slow=node;
        while(fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    private ListNode mergeSort(ListNode node){
        if(node==null || node.next==null){
            return node;
        }
        ListNode middleNode = getMiddle(node);
        ListNode middleNodeNext = middleNode.next;
        middleNode.next = null;
        ListNode left = mergeSort(node);
        ListNode right = mergeSort(middleNodeNext);
        return sort(left,right);
    }
    private ListNode sort(ListNode node1, ListNode node2){
        ListNode res = null;
        if(node1 == null){
            return node2;
        }
        if(node2 == null){
            return node1;
        }
        if(node1.val <= node2.val){
            res = node1;
            res.next = sort(node1.next, node2);
        }
        else{
            res = node2;
            res.next = sort(node1, node2.next);
        }
        return res;
    }
}