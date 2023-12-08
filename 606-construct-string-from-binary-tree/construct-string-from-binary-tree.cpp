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
void rootkasolution(TreeNode* &root,string &ans){
    if(root == NULL){
        return;
    }
    ans += to_string(root->val);
    if(root->left){
      // cout<<"root->left ki val "<<root->val<<endl;
        ans += '(';
        rootkasolution(root->left,ans);
        ans += ')';
    }

    if(root->right){
      if(root->left == NULL){
        ans += "()";
      }
      // cout<<"root->right ki val "<<root->val<<endl;
        ans += '(';
        rootkasolution(root->right,ans);
        ans += ')';
    }

}
    string tree2str(TreeNode* root) {
        string ans = "";
        rootkasolution(root,ans);
        return ans;
    }
};