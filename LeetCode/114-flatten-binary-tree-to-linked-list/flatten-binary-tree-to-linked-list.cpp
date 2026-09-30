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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur->left) {
                TreeNode* prev = cur->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = cur->right;   // attach old right subtree to rightmost of left
                cur->right = cur->left;     // move left subtree to right
                cur->left = NULL;           // clear left pointer
            }
            cur = cur->right;               // move right, not left
        }
    }
};