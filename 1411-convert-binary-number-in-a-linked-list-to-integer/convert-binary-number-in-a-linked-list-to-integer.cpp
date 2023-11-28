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
int get_sum(ListNode* &head,int &sum){
    if(head->next == NULL){
        sum += head->val == 1? 1:0;
        return 1;
    }

    int t = get_sum(head->next,sum);
    sum += head->val == 1 ? pow(2,t):0;

    return t +1;
}
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        int y = get_sum(head,sum);
        return sum;
    }
};