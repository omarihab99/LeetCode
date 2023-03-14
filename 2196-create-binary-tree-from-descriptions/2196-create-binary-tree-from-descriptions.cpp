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
        unordered_map<int,TreeNode*> map;
        unordered_map<int,int> children;
        for(int i = 0 ; i < descriptions.size() ;i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            TreeNode* p=NULL;
            TreeNode*c = NULL;
            if(map[parent]==0){
                p = new TreeNode(parent);
                map[parent] = p;
            }
            else{
                p = map[parent];
            }
            
            
            if(map[child]==0){
                c = new TreeNode(child);
                map[child] = c;
                children[child]=1;
            }
            else{
                c=map[child];
                children[child]=1;
            }
            
            if(descriptions[i][2]==0){
                p->right = c;
            }
            else{
                p->left = c;
            }
        }
        for(int i =0 ; i < descriptions.size() ;i++){
            if(children[descriptions[i][0]]==0){
                return map[descriptions[i][0]];
            }
        }
        return NULL;
        
    }
};