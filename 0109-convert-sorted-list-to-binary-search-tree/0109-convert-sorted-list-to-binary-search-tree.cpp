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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* recursion(ListNode* start,ListNode* end){
    if(start == end)return NULL;
    ListNode* fast = start;
    ListNode* slow = start;

    while(fast->next != end){
        fast = fast->next;
        if(fast->next != end){
            fast = fast->next;
            slow = slow->next;
        }
    }
    TreeNode* node = new TreeNode(slow->val);
    node->left = recursion(start,slow);
    node->right = recursion(slow->next,end);
    return node;
}

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)return NULL;
        return recursion(head,NULL);
    }
};