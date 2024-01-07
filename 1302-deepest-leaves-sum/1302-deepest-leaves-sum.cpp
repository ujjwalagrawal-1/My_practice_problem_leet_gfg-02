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
        // if(root->left == NULL && root->right == NULL){
        //     return {level,root->val};
        // }

        // pair<int,int> a = Solve_Tree(root->left,level+1);
        // pair<int,int> b = Solve_Tree(root->right,level+1);

        // if(a.first == b.first){
        //     return {a.first,a.second + b.second};
        // }
        // else if(a.first > b.first){
        //     return {a.first,a.second};
        // }
        // else{
        //     return {b.first,b.second};
        // }
        if (root->left == nullptr && root->right == nullptr) {
            return {level, root->val};
        }

        std::pair<int, int> a = {0, 0}; // Initialize with zeros
        std::pair<int, int> b = {0, 0};

        if (root->left != nullptr) {
            a = Solve_Tree(root->left, level + 1);
        }

        if (root->right != nullptr) {
            b = Solve_Tree(root->right, level + 1);
        }

        if (a.first == b.first) {
            return {a.first, a.second + b.second};
        } else if (a.first > b.first) {
            return {a.first, a.second};
        } else {
            return {b.first, b.second};
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