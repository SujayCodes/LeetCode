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
        int len1 = 0;
        ListNode* temp = head;
        while(temp !=NULL){
            len1++;
            temp = temp->next;
        }
        if(len1 ==n) return head->next;

        int firstval = len1 -n-1;
        ListNode* t1 = head;
        for(int i=1;i<=firstval;i++){
            t1=t1->next;
        }
        t1->next = t1->next->next;

        return head;
    }
};