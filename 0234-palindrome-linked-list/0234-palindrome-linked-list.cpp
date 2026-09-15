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
    ListNode* reverselist(ListNode* head){
        if(head==NULL || head->next ==NULL) return head;
        ListNode* newhead = reverselist(head->next);
        head->next->next = head;
        head->next =NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
       
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next !=NULL && fast->next->next !=NULL){
            fast = fast->next->next;
            slow=slow->next;
        }

        ListNode* reversehalf = reverselist(slow->next);
        slow->next =NULL;

        ListNode* temp = head;
        ListNode* t1 = reversehalf;

        bool flag = true;
        while(temp!=NULL && t1!=NULL){
            if(temp->val != t1->val){
                flag = false;
                break;
            }
            temp = temp->next;
            t1=t1->next;
        }
        return flag;
    }
};