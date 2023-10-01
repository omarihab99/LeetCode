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
    HashMap<Integer, List<TreeNode>> map = new HashMap();
    public List<TreeNode> allPossibleFBT(int n) {
        List<TreeNode> res = new ArrayList();
        if(n%2==0 || n<1) return res;
        if(map.containsKey(n)) return map.get(n);
        if(n==1){
            res.add(new TreeNode(0));
            map.put(1, res);
            return res;
        }
        for(int i=1;i<n;i+=2){
            List<TreeNode> leftTree = allPossibleFBT(i);
            List<TreeNode> rightTree = allPossibleFBT(n-i-1);
            for(int j=0;j<leftTree.size();j++){
                for(int k=0;k<rightTree.size();k++){
                    TreeNode root = new TreeNode(0);
                    root.left = leftTree.get(j);
                    root.right = rightTree.get(k);
                    res.add(root);
                }
            }
        }
        map.put(n,res);
        return res;
    }
}