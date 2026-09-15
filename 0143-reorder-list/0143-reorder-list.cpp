class Solution {
public:

    // Reverse linked list - Recursive
    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;   // establish reverse link
        head->next = NULL;         // break old link

        return newHead;
    }


    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return;
        }

        // STEP 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: Separate the second half
        ListNode* second = slow->next;
        slow->next = NULL;

        // STEP 3: Reverse the second half
        second = reverseList(second);

        // STEP 4: Merge both halves alternately
        ListNode* first = head;

        while (second != NULL) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};