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
TreeNode* f(TreeNode* root,int target){
    if(root == NULL){
        return NULL;
    }
    // if(root->left == NULL && root->right ==NULL){
    //     if(root->val == target){
    //         return NULL;
    //     }
    //     else{
    //         return root;
    //     }
    // }
    root->left = f(root->left,target);
    root->right =  f(root->right,target);


    if(root->left == NULL && root->right ==NULL){
        if(root->val == target){
            return NULL;
        }
        else{
            return root;
        }
    }
    else{
            return root;
        }
}
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return f(root,target);
    }
};