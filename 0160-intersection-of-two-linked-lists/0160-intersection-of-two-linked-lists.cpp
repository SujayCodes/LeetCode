class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int len1 = 0;
        int len2 = 0;

        ListNode* t1 = headA;
        while(t1 != NULL) {
            len1++;
            t1 = t1->next;
        }

        ListNode* t2 = headB;
        while(t2 != NULL) {
            len2++;
            t2 = t2->next;
        }

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Move the longer list ahead
        if(len1 > len2) {
            int diff = len1 - len2;

            for(int i = 0; i < diff; i++) {
                tempA = tempA->next;
            }
        }
        else if(len2 > len1) {
            int diff = len2 - len1;

            for(int i = 0; i < diff; i++) {
                tempB = tempB->next;
            }
        }

        // Now both have the same number of nodes remaining
        while(tempA != NULL && tempB != NULL) {

            if(tempA == tempB) {
                return tempA;
            }

            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
};