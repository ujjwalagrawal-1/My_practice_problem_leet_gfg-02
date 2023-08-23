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
bool solve(TreeNode* root,long long int lowerbound,long long int upperbound){
    if(root == NULL){
        return true;
    }
    if(root->val>lowerbound && root->val<upperbound){
        bool first = solve(root->right,root->val,upperbound); 
        bool second = solve(root->left,lowerbound,root->val); 
        return first && second;
    }
    else{
        return false;
    }
}
    bool isValidBST(TreeNode* root) {
        long long int upperbound = 4294967296;
        long long int lowerbound = -4294967296;
        return solve(root,lowerbound,upperbound);
    }
};