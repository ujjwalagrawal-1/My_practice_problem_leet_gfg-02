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
 #define node TreeNode
class Solution {
public:
void f(node* &root,int &x){
    // base case
    if(root == NULL){
        return;
    }
    f(root->right,x);
    root->val += x;
    x = root->val;
    f(root->left,x);
}
    TreeNode* convertBST(TreeNode* root) {
        int x = 0;
        f(root,x);
        return root;
    }
};