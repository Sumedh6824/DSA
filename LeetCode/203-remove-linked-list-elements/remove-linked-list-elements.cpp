/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 1. Remove matching nodes at the front
        while (head != nullptr && head->val == val) {
            ListNode* t = head;
            head = head->next;
            delete t;
        }

        // 2. Remove matching nodes in the rest of the list
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* t = cur->next;   // node to delete
                cur->next = t->next;       // bypass it
                delete t;                  // don't advance cur
            } else {
                cur = cur->next;           // advance only when nothing was removed
            }
        }
        return head;
    }
};