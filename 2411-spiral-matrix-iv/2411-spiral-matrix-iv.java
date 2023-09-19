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
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] res = new int[m][n];
        int[] dr = {0,1,0,-1};
        int[] dc = {1,0,-1,0};
        int x=0,y=0,di=0;
        boolean[][] seen = new boolean[m][n];
        for(int i=0;i<m*n;i++){
            res[x][y] = head!=null ? head.val : -1; 
            seen[x][y] = true;
            int currentR = x + dr[di];
            int currentC = y + dc[di];
            if(currentR >= 0 && currentR < m && currentC >= 0 && currentC < n && !seen[currentR][currentC]){
                x = currentR;
                y = currentC;
            }
            else{
                di = (di+1) %4;
                x+=dr[di];
                y+=dc[di];
            }
            if(head!=null){head = head.next;}
        }
        return res;
    }
}