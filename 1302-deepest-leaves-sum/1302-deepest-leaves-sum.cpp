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
    pair<int,int> Solve_Tree(TreeNode* &root,int level){
        if(root->left == NULL && root->right == NULL){
            return {level,root->val};
        }
        pair<int,int> a ;
        pair<int,int> b ;
        if(root->left != NULL)
        a = Solve_Tree(root->left,level+1);
        if(root->right != NULL)
        b = Solve_Tree(root->right,level+1);

        if(a.first == b.first){
            return {a.first,a.second + b.second};
        }
        else if(a.first > b.first){
            return {a.first,a.second};
        }
        else{
            return {b.first,b.second};
        }
    }
    int deepestLeavesSum(TreeNode* &root) {
        if(root == NULL){
            return 0;
        }
        pair<int,int> ans = Solve_Tree(root,0);
        return ans.second;
    }
};