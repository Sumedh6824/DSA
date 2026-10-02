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
    bool isValidBST(TreeNode* root) {
        vector<int> temp;
        inorderTraversal(root,temp);
        int var1 = 0;
        int var2 = 1;
        while(var2 < temp.size()){
            if(temp[var2] > temp[var1]){
                var2++;
                var1++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<int> inorderTraversal(TreeNode* root,vector<int>& temp) {
        // vector<int> temp;
        helper(root,temp);
        return temp;
    }

    void helper(TreeNode* root, vector<int> &temp){
        if(root == NULL)return;
        helper(root->left, temp);
        temp.push_back(root->val);
        helper(root->right, temp);
    }
};