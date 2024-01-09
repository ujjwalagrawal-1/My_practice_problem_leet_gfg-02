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
    void storeleaf(TreeNode* root,vector<int> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
            return;
        }

        storeleaf(root->left,ans);
        storeleaf(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        storeleaf(root1,a);
        storeleaf(root2,b);

        if(a == b)return 1;
        else return 0;
    }
};