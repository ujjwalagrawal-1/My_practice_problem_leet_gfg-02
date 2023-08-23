/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        // if((p->val < root->val && q->val > root->val) || (p->val < root->val && q->val > root->val)){
        //     //p is in left part
        //     return root;
        // }
        if(p->val < root->val && q->val < root->val){
            TreeNode* temp =  lowestCommonAncestor(root->left,p,q);
            return temp;
        }
        if(p->val > root->val && q->val > root->val){
            TreeNode* temp =  lowestCommonAncestor(root->right,p,q);
            return temp;
        }
        return root;
    }
};