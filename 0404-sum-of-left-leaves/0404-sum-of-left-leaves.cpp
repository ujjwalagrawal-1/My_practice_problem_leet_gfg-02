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
int calc(TreeNode* &root,bool flag){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL && flag){
        return root->val;
    }
    int a = calc(root->left,true);
    int b = calc(root->right,false);

    return a + b;
}
    int sumOfLeftLeaves(TreeNode* root) {
        return calc(root,0);
    }
};