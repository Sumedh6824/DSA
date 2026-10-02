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
    int kthSmallest(TreeNode* root, int k) {
        int temp = 0;
        int cnt = 0;
        helper(root,temp,cnt,k);
        return temp;
    }

    void helper(TreeNode* root, int &temp,int &cnt,int &k){
        if(root == NULL)return;
        helper(root->left, temp,cnt,k);
        cnt++;
        if(cnt == k){
            temp = root->val;
            return;
        }
        helper(root->right, temp,cnt,k);
    }
};