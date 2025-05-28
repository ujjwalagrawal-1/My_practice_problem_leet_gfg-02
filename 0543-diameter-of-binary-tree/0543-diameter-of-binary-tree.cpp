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
int f(TreeNode* &root,int &ans){
    if(root == NULL){
        return 0;
    }
    int l = f(root->left,ans);
    int r = f(root->right,ans);
    ans = max(ans,l + r);
    return max(l,r) + 1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        f(root,ans);
        return ans;
    }
};