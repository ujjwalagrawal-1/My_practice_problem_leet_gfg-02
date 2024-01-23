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
void solve(TreeNode* root,pair<int,int> &val,int level){
    if(root == NULL){
        return;
    }
    if(val.first < level){
        val = {level,root->val};
    }
    solve(root->left,val,level+1);
    solve(root->right,val,level+1);
}
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int> val = {INT_MIN,0} ;
        solve(root,val,0);
        return val.second;
    }
};