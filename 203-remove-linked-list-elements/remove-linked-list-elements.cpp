class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        // Remove elements from the beginning
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        ListNode* temp = head;
        ListNode* x = head;

        while (temp != nullptr) {
            while (temp != nullptr && temp->val != val) {
                x = temp;
                temp = temp->next;
            }

            // Update x->next
            if (temp != nullptr) {
                x->next = temp->next;
                temp = temp->next;
            }
        }

        return head;
    }
};
