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
int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
TreeNode* f(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int a = height(root->left);
    int b = height(root->right);
    if(a == b){
        return root;
    }
    else{
        if(a>b){
            return f(root->left);
        }
        else{
            return f(root->right);
        }
        
    }
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return f(root);
    }
};