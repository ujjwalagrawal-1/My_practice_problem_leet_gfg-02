class Solution {
public:
    ListNode* reverse(ListNode* root){
        ListNode* prev = NULL;
        ListNode* current = root;
        ListNode* next = NULL;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode* solve(ListNode* l1, ListNode* l2){
        ListNode* temp = new ListNode(-1);
        ListNode* result = temp;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            sum %= 10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return result->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        return reverse(solve(l1, l2));
    }
};
