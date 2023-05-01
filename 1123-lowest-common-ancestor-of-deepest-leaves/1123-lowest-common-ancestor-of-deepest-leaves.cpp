/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* a;
    int max_d=0;
    int m(TreeNode* root, int depth){
        max_d = max(max_d, depth);
        if(!root) return depth;
        int l = m(root->left, depth+1);
        int r = m(root->right, depth+1);
        if(l == max_d && r == max_d) a=root;
        return max(l, r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        m(root, 0);
        return a;
    }
};