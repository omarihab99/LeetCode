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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr;
        vector<int> v1;
        vector<int> v2;
        inorder(root1,v1);
        inorder(root2, v2);
        int i=0, j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i] <= v2[j]) arr.push_back(v1[i++]);
            else arr.push_back(v2[j++]);
        }
        while(i<v1.size()) arr.push_back(v1[i++]);
        while(j<v2.size()) arr.push_back(v2[j++]);
        return arr;
    }
    void inorder(TreeNode* root, vector<int> &v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
};