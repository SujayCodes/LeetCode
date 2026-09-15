class Solution {
public:

    ListNode* reverselist(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* newhead = reverselist(head->next);

        head->next->next = head;
        head->next = NULL;

        return newhead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || head->next == NULL || left == right)
            return head;

        // Special case: left = 1
        if(left == 1) {

            ListNode* t2 = head;

            // Move t2 to right
            for(int i = 1; i <= right - 1; i++) {
                t2 = t2->next;
            }

            // Save node after right
            ListNode* nextv = t2->next;

            // Detach the portion
            t2->next = NULL;

            // Reverse from head
            ListNode* reversing = reverselist(head);

            // Find tail of reversed portion
            ListNode* t3 = reversing;

            while(t3->next != NULL) {
                t3 = t3->next;
            }

            // Connect to remaining list
            t3->next = nextv;

            return reversing;
        }

        // t1 = node BEFORE left
        ListNode* t1 = head;

        for(int i = 1; i <= left - 2; i++) {
            t1 = t1->next;
        }

        // t2 = right node
        ListNode* t2 = t1->next;

        for(int i = left; i <= right - 1; i++) {
            t2 = t2->next;
        }

        // Save node after right
        ListNode* nextv = t2->next;

        // Detach sublist
        t2->next = NULL;

        // Reverse [left ... right]
        ListNode* reversing = reverselist(t1->next);

        // Connect previous part to reversed part
        t1->next = reversing;

        // Find tail of reversed part
        ListNode* t3 = reversing;

        while(t3->next != NULL) {
            t3 = t3->next;
        }

        // Connect reversed part to remaining list
        t3->next = nextv;

        return head;
    }
};