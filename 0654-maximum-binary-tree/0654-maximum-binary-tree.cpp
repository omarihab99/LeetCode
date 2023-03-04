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
        return construct(nums, 0, nums.size());
    }
    TreeNode* construct(vector<int> nums, int i, int j){
        if(i==j) return NULL;
        int max_idx = max(nums, i, j);
        TreeNode* root = new TreeNode(nums[max_idx]);
        root->left = construct(nums, i, max_idx);
        root->right = construct(nums, max_idx+1, j);
        return root;
    }
    int max(vector<int> nums, int i, int j){
        int max_idx = i;
        for(int k = i; k<j;k++){
            if(nums[k] > nums[max_idx]) max_idx = k;
        }
        return max_idx;
    }
    
};