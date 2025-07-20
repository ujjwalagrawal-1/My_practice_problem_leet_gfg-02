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
using node = TreeNode;
node* prev = nullptr;
void f(node* root){
    if(root == nullptr)return;
    f(root->right);
    f(root->left);
    root->left = nullptr;
    root->right = prev;
    prev = root;
}
    void flatten(TreeNode* root) {
        f(root);
    }
};