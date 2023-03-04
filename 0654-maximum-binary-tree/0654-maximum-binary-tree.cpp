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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> s;
        TreeNode* root = NULL;
        for(int i=0;i<nums.size(); i++)
        {
            TreeNode* c = new TreeNode(nums[i]);
            while(!s.empty() && s.top()->val < c->val){
                c->left = s.top();
                s.pop();
            }
            if(!s.empty()){
                s.top()->right = c;
            }
            else{
                root=c;
            }
            s.push(c);
        }
        return root;
    }
};