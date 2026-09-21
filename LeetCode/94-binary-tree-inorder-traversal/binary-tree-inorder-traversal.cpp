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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> temp;
        helper(root,temp);
        return temp;
    }
private:
    void helper(TreeNode* root, vector<int> &temp){
        if(root == NULL)return;
        helper(root->left, temp);
        temp.push_back(root->val);
        helper(root->right, temp);
    }    
};