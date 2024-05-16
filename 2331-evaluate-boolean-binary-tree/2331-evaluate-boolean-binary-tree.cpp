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
int f(TreeNode* &root){
    if(root->left == NULL || root->right == NULL ){
        return root->val;
    }

    int lft = f(root->left);
    int rgt = f(root->right);
    if(root->val == 2){
        return lft|rgt;
    }
    else{
        return lft&rgt;
    }
}
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};