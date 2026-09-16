/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy next node's value into this node
        node->val = node->next->val;
        // Bypass the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};