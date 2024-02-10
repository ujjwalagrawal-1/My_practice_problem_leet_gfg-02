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
int len(ListNode* &head){
    ListNode* temp = head;
    int len = 1;
    while(temp){
        temp = temp->next;
        len++;
    }
    return len;
}
    int pairSum(ListNode* head) {
        int n = len(head);
        int maxi = INT_MIN;
        ListNode* temp = head;
        stack<int> st;
        int y = len(head)/2;
        while(y--){
            st.push(temp->val);
            temp = temp->next;
        }
        while(temp){
            maxi = max(temp->val+st.top(),maxi);
            st.pop();
            temp = temp->next;
        }
        return maxi;
    }
};