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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int len1=0;
        int len2=0;
        while(temp1!=NULL){
            len1++;
            temp1=temp1->next;
        }

         while(temp2!=NULL){
            len2++;
            temp2=temp2->next;
        }

        ListNode* fast;
        ListNode* slow;

        int max=0; int diff=0;
        if(len1>len2){
            max=len1;
            diff=max-len2;
            fast=headA;
            slow=headB;
        }    
        else{
            max=len2;
            diff=max-len1;
            fast=headB;
            slow=headA;
        }    

        

        for(int i=1;i<=diff;i++){
            fast=fast->next;
        }


        while(fast != slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;

        
    }
};