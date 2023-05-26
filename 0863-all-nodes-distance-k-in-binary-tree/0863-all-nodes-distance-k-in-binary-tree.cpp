/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>> graph;
    unordered_map<int,bool> visited;
    vector<int> res;
    void graph_builder(TreeNode*child, TreeNode*parent){
        if(child && parent){
            graph[child->val].push_back(parent->val);
            graph[parent->val].push_back(child->val);
        }
        if(child->left) graph_builder(child->left, child);
        if(child->right) graph_builder(child->right, child);
    }
    void bfs(int node, int dist, int k){
        queue<array<int,2>> queue;
        queue.push({node,dist});
        while(!queue.empty()){
            auto [current,d] = queue.front();
            queue.pop();
            if(d==k) {res.push_back(current);continue;}
            for(auto n : graph[current]){
                if(!visited[n]){
                    visited[n] = true;
                    queue.push({n,d+1});
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        graph_builder(root, NULL);
        visited[target->val] = true;
        bfs(target->val, 0,k);
        return res;
    }
};