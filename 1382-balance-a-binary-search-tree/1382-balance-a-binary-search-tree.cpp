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
vector<int> a;
void inorder(TreeNode* root){
    if(root == 0){
        return;
    }
    inorder(root->left);
    a.push_back(root->val);
    inorder(root->right);
}
TreeNode* f(int s ,int e){
    if(s > e){
        return NULL;
    }

    int mid = s + (e -s)/2;

    TreeNode* newnode = new TreeNode(a[mid]);
    newnode->left = f(s,mid - 1);
    newnode->right = f(mid+1,e);


    return newnode;
}
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        sort(a.begin(),a.end());
        return f(0,a.size()-1);
    }
};