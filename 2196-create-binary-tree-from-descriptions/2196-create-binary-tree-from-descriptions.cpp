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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> m;
        unordered_set<int> ch;
        unordered_set<int> pr;
        for(int i=0;i<descriptions.size();i++){
            int p = descriptions[i][0];
            int c = descriptions[i][1];
            int l = descriptions[i][2];
            if(m[p]==0)
                m[p] = new TreeNode(p);
            if(m[c]==0)
                m[c] = new TreeNode(c);
            if(l==1) m[p]->left=m[c];
            else m[p]->right=m[c];
            ch.emplace(c);
            pr.emplace(p);
            if(ch.find(p)!=ch.end()) pr.erase(p);
            if(pr.find(c)!=pr.end()) pr.erase(c);
        }
        int root = *pr.begin();
        return m[root];
        
    }
};