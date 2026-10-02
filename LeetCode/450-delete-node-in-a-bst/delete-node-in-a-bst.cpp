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
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL) return root;
//         TreeNode* parent = NULL;
//         TreeNode* temp = root;
//         while(temp != NULL){
//             if(temp->val == key){
//                 TreeNode* replacement;
//                 if(temp->right != NULL){
//                     TreeNode* smaller = temp->right;
//                     while(smaller->left != NULL){
//                         smaller = smaller->left;
//                     }
//                     smaller->left = temp->left;
//                     replacement = temp->right;
//                     if(parent->val < key){
//                         parent->right = temp->right;
//                     }
//                     else{
//                         parent->left = temp->right;
//                     }
//                     delete temp;
//                     break;
//                 }
//                 else{
//                     if(temp->left != NULL){
//                         if(parent->val < key){
//                             parent->right = temp->left;
//                         }
//                         else{
//                             parent->left = temp->left;
//                         }
//                         delete temp;
//                         break;
//                     }
//                     else{
//                         parent->left = NULL;
//                         delete temp;
//                         break;
//                     }
//                 }
//             }
//             if(temp->val < key){
//                 parent = temp;
//                 temp = temp->right;
//             } 
//             else{
//                 parent = temp;
//                 temp = temp->left;
//             } 
//         }
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        TreeNode* parent = NULL;
        TreeNode* temp = root;
        while(temp != NULL){
            if(temp->val == key){
                TreeNode* replacement;
                if(temp->right != NULL){
                    TreeNode* smaller = temp->right;
                    while(smaller->left != NULL){
                        smaller = smaller->left;
                    }
                    smaller->left = temp->left;
                    replacement = temp->right;
                }
                else{
                    replacement = temp->left;   // may be NULL (leaf)
                }

                if(parent == NULL) root = replacement;
                else if(parent->left == temp) parent->left = replacement;
                else parent->right = replacement;

                delete temp;
                break;
            }
            parent = temp;
            if(temp->val < key) temp = temp->right;
            else temp = temp->left;
        }
        return root;
    }
};