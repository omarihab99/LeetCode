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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* c = s.top();
            s.pop();
            cout << c->val << "\n";
            if(c->right == nullptr && c->left == nullptr && !s.empty())
            {
                c->right = s.top();
                
            }
            else{
                if(c->right != nullptr)
            {
                s.push(c->right);
            }
            if(c->left != nullptr)
            {
                s.push(c->left);
                c->right = c->left;
                c->left=nullptr;
            } 
            }
           
            
        }
    }
};