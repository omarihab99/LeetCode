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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return convert(v, 0, v.size()-1);
    }
    void inorder(TreeNode* root, vector<int> &v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    TreeNode* convert(vector<int> a, int start, int end){
        if(start>end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = convert(a, start, mid-1);
        root->right = convert(a, mid+1, end);
        return root;
    }
};