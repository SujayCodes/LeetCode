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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* t1 = head;
        int len = 0;
        while(t1 !=NULL){
            len++;
            t1 = t1->next;
        }
        if(n == len) {
            return head->next;
        }
        for(int i=1;i<=len-n-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};