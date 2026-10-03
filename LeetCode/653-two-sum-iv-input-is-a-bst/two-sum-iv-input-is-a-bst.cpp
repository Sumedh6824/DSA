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
    bool findTarget(TreeNode* root, int k) {
        vector<int> temp;
        inorderTraversal(root,temp);
        int n = temp.size();
        int left = 0 , right = n-1;
        while(left < right){
            if(temp[left] + temp[right] == k) return true;
            if(temp[left] + temp[right] < k){
                left = left + 1;
            }
            else{
                right = right - 1;
            }
        }
        return false;
    }
    
private:
    vector<int> inorderTraversal(TreeNode* root,vector<int> &temp) {
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