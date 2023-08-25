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
void sumofthetree(TreeNode* root,int& reqsum,int num){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        num = num*10 + root->val;
        reqsum += num;
        return;
    }
    num = num*10 + root->val;
    sumofthetree(root->left,reqsum,num);
    sumofthetree(root->right,reqsum,num);
}
int sumNumbers(TreeNode* root) {
    int req = 0;int num = 0;
    sumofthetree(root,req,num);
    return req;
}
};