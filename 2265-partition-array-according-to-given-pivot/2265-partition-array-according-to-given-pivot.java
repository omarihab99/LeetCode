class ListNode{
    int val;
    ListNode next;
    public ListNode(){}
    public ListNode(int value){val=value;}
}
class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        ListNode smallTail = new ListNode();
        ListNode smallHead = smallTail;
        ListNode greatTail = new ListNode();
        ListNode greatHead = greatTail;
        ListNode equalTail = new ListNode();
        ListNode equalHead = equalTail;
        for(int num:nums){
            ListNode current = new ListNode(num); 
            if(num<pivot){
                smallTail.next = current;
                smallTail = smallTail.next;
            }
            else if(num>pivot){
                greatTail.next = current;
                greatTail = greatTail.next;
            }
            else{
                equalTail.next = current;
                equalTail = equalTail.next;
            }
        }
        smallTail.next = equalHead.next;
        equalTail.next = greatHead.next;
        greatTail.next = null;
        smallHead = smallHead.next;
        int[] res = new int[nums.length];
        int i = 0;
        while(smallHead!=null){
            System.out.println(smallHead.val);
            res[i] = smallHead.val;
            i++;
            smallHead = smallHead.next;
        }
        return res;
    }
}