/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode[] SplitListToParts(ListNode head, int k) {
        ListNode current = head;
        int n=0;
        while(current != null) {
            n++;
            current = current.next;
        }
        ListNode[] ans = new ListNode[k];
        int r = n % k;
        int w = n / k;
        current = head;
        for(int i=0; i<k;i++){
            ListNode root = current;
            for(int j=0; j < w + (i < r ? 1 : 0) - 1; j++){
                if(current!=null){
                    current = current.next;
                }
            }
            if(current != null){
                ListNode temp = current;
                current = current.next;
                temp.next = null;
            }
            ans[i] = root;
        }
        return ans;
    }
}