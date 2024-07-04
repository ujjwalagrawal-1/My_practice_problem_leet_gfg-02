class Solution {
public:
ListNode* Done(ListNode* &head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* ans = new ListNode(0); 
    ListNode* temp = head;
    ListNode* p = ans;
    while (temp != NULL) {
        int cal = 0;
        while (temp != NULL && temp->val != 0) {
            cal += temp->val;
            temp = temp->next;
        }
        if (cal != 0) {
            ListNode* newnode = new ListNode(cal);
            p->next = newnode;
            p = p->next;
        }
        if (temp != NULL) {
            temp = temp->next;
        }
    }
    return ans->next; // Return the next of dummy node
}

ListNode* mergeNodes(ListNode* head) {
    // Remove leading zeros
    while (head != NULL && head->val == 0) {
        head = head->next;
    }
    return Done(head);
}
};