class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        boolean foundLeft = false;
        ListNode t = head;
        List<ListNode> arr = new ArrayList();
        int i=0,p1=0,p2=0;
        while(t!=null){
            p1++;
            p2++;
            if(p1==left) foundLeft = true;
            if(foundLeft){
                arr.add(i,t);
                i++;
            }
            if(p2 == right){
                int f = 0;
                while(f<i){
                    ListNode LNode = arr.get(f++);
                    ListNode RNode = arr.get(--i);
                    int temp = LNode.val;
                    LNode.val = RNode.val;
                    RNode.val = temp;
                }
                break;           
            }
            t = t.next;
        }
        return head;
    }
}