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
int solve_using_recursion(TreeNode* &root,map<TreeNode*,int> &hash){
    if(root == NULL){
        return 0;
    }
    if(hash.count(root)){
        return hash[root];
    }
    int a = solve_using_recursion(root->left,hash);
    int b = solve_using_recursion(root->right,hash);

    int ans = root->val;
    if(root->left){
        int a = solve_using_recursion(root->left->left,hash);
        int b = solve_using_recursion(root->left->right,hash);
        ans += (a+b);
    }
    if(root->right){
        int a = solve_using_recursion(root->right->left,hash);
        int b = solve_using_recursion(root->right->right,hash);
        ans += (a+b);
    }

    return hash[root] = max({ans,a+b});
    
}
// applying Memoisation()
    int rob(TreeNode* &root) {
        map<TreeNode*,int> hash;
        return solve_using_recursion(root,hash);
    }
};