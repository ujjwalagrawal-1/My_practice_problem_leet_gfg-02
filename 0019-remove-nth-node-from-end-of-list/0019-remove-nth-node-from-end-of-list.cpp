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
void reverse(ListNode* &head){
    ListNode* prev = NULL;
    ListNode* temp = head;
    while(temp != NULL){
        ListNode* forwa = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forwa;
    }
    head = prev;
    // return head;
}
int length(ListNode* &head){
    int l = 1;
    ListNode* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
        l++;
    }
    return l;
}
    ListNode* removeNthFromEnd(ListNode* head, int n){
        // reverse(head);
        //Node to remove 
        n = length(head) - n;
        n++;
        if(n == 1){
            if(length(head) == 1)
            return NULL;
            else{
                head = head->next;
                return head;
            }
        }
        if(n == 2){
            if(length(head) == 2)
            {
            head->next = NULL;
            return head;
            }
            else{
                head->next = head->next->next;
                return head;
            }
            
        }
        int l = 1;
        // cout<<length(head);
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = head->next;
        if(head->next == NULL){
            return NULL;
        }

        while(l<=n-1){
        prev = curr;
        curr = forw;
        forw = forw->next;
        l++;
        }
        prev->next = forw;
        delete curr;
        // reverse(head);
        return head;
    }
};