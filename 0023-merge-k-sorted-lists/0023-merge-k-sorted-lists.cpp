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
ListNode* mergeTwoLists(ListNode* &left, ListNode* &right) {
        if(left == 0){
            return right;
        }
        if(right == 0){
            return left;
        }
        // ListNode* ans = 0;
        if(left->val<right->val){
            left->next = mergeTwoLists(left->next,right);
            return left;
        }
        else{
            // ans = right;
            right->next = mergeTwoLists(left,right->next);
            return right;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* temp = new ListNode(INT_MIN);
        for(auto itr:lists){
            temp = mergeTwoLists(itr,temp);
        }
        return temp->next;
    }
};