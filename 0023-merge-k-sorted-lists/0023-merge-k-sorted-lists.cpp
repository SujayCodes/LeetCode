class Solution {
public:

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Put first node of every list into heap
        for (ListNode* node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // Smallest value node
            ListNode* temp = pq.top();
            pq.pop();

            // Add it to answer
            tail->next = temp;
            tail = tail->next;

            // Put next node from same list
            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        }

        return dummy.next;
    }
};