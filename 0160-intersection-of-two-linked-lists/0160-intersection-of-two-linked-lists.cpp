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
        int n1 = 0 ; int n2 = 0;
        ListNode* t1 = headA; 
        ListNode* t2 = headB;
        while(t1 !=NULL){
            n1++;
            t1=t1->next;
        }
        while(t2 !=NULL){
            n2++;
            t2=t2->next;
        }
        ListNode* fast;
        ListNode* slow;

        if(n1>n2){
            int diff = (n1-n2);
            fast = headA;
            slow = headB;
            for(int i=1;i<=diff;i++){
                fast = fast->next;
            }
        }
        else{
            int diff = (n2-n1);
            fast = headB;
            slow = headA;
            for(int i=1;i<=diff;i++){
                fast = fast->next;
            }
        }

        while(fast != slow){
            fast = fast->next;
            slow= slow->next;
        }
        return slow;
    }
};