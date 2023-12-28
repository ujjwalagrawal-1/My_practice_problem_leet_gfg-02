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
void solve(TreeNode* &root,int low,int high,int &data){
    if(root == NULL){
        return;
    }
    if(root->val<low){
        solve(root->right,low,high,data);
    }
    else if(root->val>high){
        solve(root->left,low,high,data);
    }
    else{
    data += root->val;
    solve(root->left,low,high,data);
    solve(root->right,low,high,data);
    }
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        solve(root,low,high,sum);
        return sum;
    }
};