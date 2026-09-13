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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* t1 = head;
        ListNode* t2 = head;
    
        int len1 =0;
        while(t1!=NULL){
            len1++;
            t1 = t1->next;
        }
        if(k==0 || len1==0) return head;

        k = k%len1;
        while(t2->next !=NULL){
            t2 = t2->next;
        }
        t2->next = head;

        ListNode *h = head;
        ListNode* tp = head;

        for(int i=1;i<=len1-k;i++){
            h = h->next;
        }

        while(tp->next != h){
            tp=tp->next;
        }
        tp->next = NULL;

        return h;

        




    }
};