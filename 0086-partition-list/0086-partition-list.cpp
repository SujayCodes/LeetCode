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
    ListNode* partition(ListNode* head, int x) {
        ListNode* a = new ListNode(100);
        ListNode* b = new ListNode(200);

        ListNode* t1 = a;
        ListNode* t2 = b;

        ListNode * temp = head;

        while(temp !=NULL){
            ListNode* nextNode = temp->next;
            if(temp->val <x){
                t1->next = temp;
                t1=t1->next;
            }
            else{
                t2->next = temp;
                t2 = t2->next;
            }
            temp->next=NULL;
            temp = nextNode;
        }
        t1->next = b->next;
        return a->next;
    }
};