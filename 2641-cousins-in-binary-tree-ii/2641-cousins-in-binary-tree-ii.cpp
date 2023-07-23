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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({NULL, root});
        while(q.size()){
            int size = q.size();
            vector<pair<TreeNode*, TreeNode*>> mod;
            unordered_map<TreeNode*, int> map;
            int sum=0;
            while(size--){
                auto current = q.front();
                q.pop();
                auto currentParent = current.first;
                auto currentChild = current.second;
                sum+= currentChild->val; // sum of all nodes in same level
                map[currentParent]+= currentChild->val; // sum of parent's children
                mod.push_back({currentParent, currentChild});
                if(currentChild->left) q.push({currentChild, currentChild->left});
                if(currentChild->right) q.push({currentChild, currentChild->right});
            }
            for(auto pr : mod){
                int modifyVal = sum - map[pr.first];
                pr.second->val = modifyVal;
            }
        }
        return root;
    }
};