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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int levelsize = q.size();
            vector<int> currentlevel;
            for(int i=0;i<levelsize;i++){
                TreeNode* currentNode = q.front();
                q.pop();
                currentlevel.push_back(currentNode->val);
                if(currentNode->left != nullptr) q.push(currentNode->left);
                if(currentNode->right != nullptr) q.push(currentNode->right);
            }
            res.push_back(currentlevel);
        }
        return res;
    }
};