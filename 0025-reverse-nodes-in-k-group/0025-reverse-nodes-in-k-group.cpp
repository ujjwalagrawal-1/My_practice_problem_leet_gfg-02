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
int length(ListNode* &head){
    int l = 1;
    ListNode* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
        l++;
    }
    return l;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        int len = length(head);
        if(len<k){
            return head;
        }
        int l = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        while(l<k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            l++;
        }
        if(forward != NULL){
            head->next = reverseKGroup(forward,k);
        }
        return prev;
    }
};