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
pair<TreeNode*,int> f(TreeNode * root){
    if(root ==  NULL){
        return {root,0};
    }
    auto a = f(root->left);
    auto b = f(root->right);
    if(a.second == b.second){
        return {root,a.second+1};
    } 
    else{
        if(a.second > b.second){
            return {a.first,a.second+1};
        }
        else{
            return {b.first,b.second+1};
        }
    }
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
         return f(root).first;
    }
};