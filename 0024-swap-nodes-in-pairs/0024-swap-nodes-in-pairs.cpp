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
ListNode* recursively(ListNode* &head){
    if(head == NULL){
        return head;
    }
    if(2>length(head)){
        return head;
    }
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = curr->next;
    int l = 0;
    while(l<2){
        // forward = curr->next;
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        l++;
    }
    if(forward != NULL)
    head->next = recursively(forward);
    return prev;
}
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = recursively(head);
        return ans;
    }
};