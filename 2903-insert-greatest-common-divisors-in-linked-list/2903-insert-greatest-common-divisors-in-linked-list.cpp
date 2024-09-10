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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* forw = head->next;

        while(forw){
            ListNode* newnode = new ListNode(__gcd(temp->val,forw->val));

            temp->next = newnode;
            newnode->next = forw;

            temp = forw;
            forw = forw->next;
        }

        return head;
    }
};