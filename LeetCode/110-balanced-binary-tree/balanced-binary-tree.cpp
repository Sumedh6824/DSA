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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ls = maxDepth(root->left);
        if(ls == -1) return -1;
        int rs = maxDepth(root->right);
        if(rs == -1) return -1;
        if(abs(ls - rs) > 1) return -1;
        return 1 + max(ls,rs);
    }
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
};