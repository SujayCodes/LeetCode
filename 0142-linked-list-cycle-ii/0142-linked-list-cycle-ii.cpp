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
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast !=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                ListNode* t1 = head;
                while(t1 != fast){
                    t1=t1->next;
                    fast = fast->next;
                }
                return t1;
            }
        }
        return NULL;
    }
};