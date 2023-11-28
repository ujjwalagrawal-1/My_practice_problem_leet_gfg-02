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
ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = curr;
        while(curr != NULL){
            forw = forw->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
}
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }

        ListNode* root = slow->next;
        root = reverseList(root);
        slow->next = NULL;
        cout<<slow->val;
        ListNode* temp = head;
        ListNode* forw = head->next;
        while(temp != NULL && root !=NULL){
            ListNode* ele;
            if(root != NULL){
                ele = root;
                root = root->next;
                ele-> next = NULL;
            }
            temp->next = ele;
            ele->next = forw;
            temp = forw;
            if(forw != NULL)
            forw = forw->next;
        }
    }
};