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
    public int NumComponents(ListNode head, int[] nums) {
        HashSet<int> set = new HashSet<int>();
        bool comp = false;
        for(int i=0;i<nums.Length;i++){
            set.Add(nums[i]);
        }
        int res = 0;
        ListNode current = head;
        while(current!=null){
            if(set.Contains(current.val)){
                comp = true;
            } else {
                if(comp) res++;
                comp = false;
            }
            current = current.next;
        }
        return res + (comp ? 1 : 0);
    }
}