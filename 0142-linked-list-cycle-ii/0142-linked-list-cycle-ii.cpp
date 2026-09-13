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
        ListNode* fast=head;
        ListNode* slow=head;
        
        
        while(fast!=NULL && fast->next !=NULL){
            fast=fast->next->next;
            slow=slow->next;
         
            if(fast==slow){
                ListNode* temp1=head;
                while(temp1 !=slow){
                    temp1=temp1->next;
                    slow=slow->next;
                }
                return temp1;
            }
        }
        
        return NULL;
        
    }
};