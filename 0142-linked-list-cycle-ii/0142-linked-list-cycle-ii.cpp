class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return NULL;
        }
        if(head->next->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {  // Check both fast and fast->next
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
            if (slow == fast) {
                slow = head;
                break;
            }
        }
        if(fast == NULL){
            return NULL;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
