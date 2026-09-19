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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int>mpp;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            mpp[temp] = cnt;
            cnt++;
            temp = temp->next;
        }
        return NULL;
    }
};