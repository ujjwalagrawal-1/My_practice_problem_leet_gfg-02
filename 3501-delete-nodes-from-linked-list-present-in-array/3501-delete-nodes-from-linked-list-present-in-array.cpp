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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(),nums.end());
        ListNode* temp = NULL;
        ListNode* curr = head;
        if(head == NULL){
            return head;
        }

        while(curr && st.count(curr->val)){
            
            temp = curr->next;
            curr->next = NULL;
            curr = temp;
        }
        head = curr;
        if(head == NULL){
            return head;
        }
        temp = NULL;
        curr = head;
        // cout<<curr->val<<endl;
        while(curr != NULL){
            if(st.count(curr->val)){
                while(curr && st.count(curr->val)){
                    curr = curr->next;
                }
                temp->next = curr;
                temp = curr;
                if(curr)
                curr = curr->next;
            }
            else{
                temp = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};