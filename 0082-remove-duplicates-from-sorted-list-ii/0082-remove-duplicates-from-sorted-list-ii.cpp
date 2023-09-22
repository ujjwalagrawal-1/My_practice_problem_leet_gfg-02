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

ListNode* solve(ListNode* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    ListNode* dummy = new ListNode(0,head);
    ListNode* prev = dummy;
    while(head){
        if(head->next && head->next->val == head->val){
        while(head->next && head->next->val == head->val){
            head = head->next;
        }
            prev->next = head->next;
        }
        else{
            prev = prev->next;
        }
        head = head->next;
    }
    return dummy->next;
}
    ListNode* deleteDuplicates(ListNode* head) {
        return solve(head);
    }
};