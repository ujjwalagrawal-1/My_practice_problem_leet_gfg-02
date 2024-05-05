/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // ListNode* temp = head;
        // if(temp->val == node->val){
        //     head = head->next;
        //     delete temp;
        // }
        // while(!(temp->next->val == node->val)){
        //     temp = temp->next;
        // }
        // if(temp->next->next == NULL){
        //     ListNode* llx = temp->next;
        //     temp->next = NULL;
        //     delete llx;
        // }
        // else{
        // ListNode* llx = temp->next;
        // temp->next = temp->next->next;
        // delete llx;
        // }
        // return head;
        ListNode* copy = node->next;
        while(copy != NULL){
            node->val = copy->val;
            copy = copy->next;
            if(copy == NULL){
                node->next = NULL;
                break;
            }
            node = node->next;
            
            
        }
        // node->next = NULL;
        delete copy;
    }
};