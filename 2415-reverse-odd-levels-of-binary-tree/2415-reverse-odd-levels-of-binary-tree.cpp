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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0, num=0;
        vector<TreeNode*> v;
        while(!q.empty()){
            num = q.size();
            while(num--){
                TreeNode* current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                if(level%2!=0) v.push_back(current);
            }
            for(int i=0;i<v.size()/2;i++){
                swap(v[i]->val, v[v.size()-1-i]->val);
            }
            v.clear();
            level++;
        }
        return root;
    }
};