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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({NULL, root});
        while(q.size()){
            int size = q.size();
            pair<TreeNode*, bool> foundFirst;
            foundFirst.second = false;
            pair<TreeNode*, bool> foundSecond; 
            foundSecond.second = false;
            while(size--){
                auto currentNode = q.front();
                auto currentParent = currentNode.first;
                auto currentChild = currentNode.second;
                q.pop();
                if(currentChild->val == x){
                    foundFirst.first = currentParent;
                    foundFirst.second = true;
                }
                if(currentChild->val == y){
                    foundSecond.first = currentParent;
                    foundSecond.second = true;
                }
                if(currentChild->left) q.push({currentChild, currentChild->left});
                if(currentChild->right) q.push({currentChild, currentChild->right});
            }
            if(foundFirst.second && foundSecond.second && foundFirst.first != foundSecond.first){
                return true;
            }
        }
        return false;
    }
};