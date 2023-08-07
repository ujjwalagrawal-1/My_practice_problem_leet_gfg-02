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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 1;
        if(head == NULL || head->next == NULL){
            return head;
        }
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        temp->next = head;
        temp = head;
        k = k%len;
        for(int i = 1;i<len-k;i++){
            temp = temp->next;
        }
        ListNode* first = temp->next;
        temp->next = NULL;
        return first;


    }
};