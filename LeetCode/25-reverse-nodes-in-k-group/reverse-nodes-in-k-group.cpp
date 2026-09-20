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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* current = head;
        ListNode* temp = current->next;
        ListNode* prev = nullptr;
        while(temp != NULL){
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }

    ListNode* getkthnode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevList = NULL;
        while(temp != NULL){
            ListNode* kthNode = getkthnode(temp,k);
            if(kthNode == NULL) {
                prevList->next = temp;
                break;
            } 

        ListNode* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseList(temp);
        if(temp == head){
            head = kthNode;
        }
        else{
            prevList->next = kthNode;
        }
        prevList = temp;
        temp = nextNode;
        }
        return head;
    }

};