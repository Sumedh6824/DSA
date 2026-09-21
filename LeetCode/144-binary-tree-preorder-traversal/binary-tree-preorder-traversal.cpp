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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> stor;
        helper(root, stor);
        return stor;
    }
private:
    void helper(TreeNode* root, vector<int>& stor){
        if(root == NULL) return;
        stor.push_back(root->val);
        helper(root->left, stor);
        helper(root->right, stor);
    }    
};