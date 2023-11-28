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
ListNode* reverse(ListNode* root){
    ListNode* temp = root;
    ListNode* prev = NULL;
    ListNode* forw = temp->next;
    while(temp != NULL){
        forw = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forw;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        temp = reverse(temp); 
        while(temp != NULL){
            if(temp->val != head->val){
                return false;
            }
            temp = temp->next;
            head = head->next;
        }
        return true;
    }
};