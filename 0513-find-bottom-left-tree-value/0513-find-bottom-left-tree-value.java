/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int lastRow=-1,lastLeft=0;
    public int findBottomLeftValue(TreeNode root) {
        check(root,0);
        return lastLeft;
    }
    private void check(TreeNode root, int currRow){
        if(root==null) return;
        if(currRow>lastRow){
            lastRow=currRow;
            lastLeft=root.val;
        }
        check(root.left,currRow+1);
        check(root.right,currRow+1);
    }
}