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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        while(head != NULL && head->val == val){
            head = head->next;
        }

        ListNode* temp = head;
        ListNode* x = head;
        while(temp != NULL){
             while (temp != NULL) {
            while (temp != NULL && temp->val != val) {
                x = temp;
                temp = temp->next;
            }
            if (temp != NULL) {
                x->next = temp->next;
                temp = temp->next;
            }
        }
        }
        return head;
    }
};