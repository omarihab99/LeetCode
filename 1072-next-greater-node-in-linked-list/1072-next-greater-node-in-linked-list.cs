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
    public int[] NextLargerNodes(ListNode head) {
        List<int> arr = new List<int>();
        ListNode current = head;
        while(current != null){
            arr.Add(current.val);
            current = current.next;
        }
        int[] ans = new int[arr.Count];
        Stack<int> stack = new Stack<int>();
        for(int i=0;i<ans.Length;i++){
            while(stack.Count != 0 && arr[stack.Peek()] < arr[i]){
                ans[stack.Pop()] = arr[i];
            }
            stack.Push(i);
        }
        return ans;
    }
}