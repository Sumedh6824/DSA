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
    ListNode* getlastNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp != NULL){
            if(cnt == k)return temp;
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len += 1;
        }
        if(k % len == 0) return head;
        k = k% len;
        tail->next = head;
        ListNode* newlastnode = getlastNode(head,len - k);
        head = newlastnode->next;
        newlastnode->next = NULL;
        return head;
    }
};