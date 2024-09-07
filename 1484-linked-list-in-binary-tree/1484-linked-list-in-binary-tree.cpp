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
bool f(ListNode* head,TreeNode* root){
    if(head == NULL){
        return true;
    }
    if(root == NULL){
        return false;
    }

    bool ans = false;
    if(head->val == root->val){
        ans |= f(head->next,root->left) || f(head->next,root->right);
    }
    return ans;
}
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        if(head == NULL){
            return true;
        }
        bool ans = false;
        if(root->val == head->val){
            ans |= f(head,root);
        }
        return isSubPath(head,root->left) || isSubPath(head,root->right) || ans;
    }
};