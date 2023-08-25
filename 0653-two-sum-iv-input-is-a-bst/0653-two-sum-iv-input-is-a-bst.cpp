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
void Inorder_traversal(TreeNode* &root,vector<int> &inorder){
    if(root == NULL){
        return;
    }
    Inorder_traversal(root->left,inorder);
    inorder.push_back(root->val);
    Inorder_traversal(root->right,inorder);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        Inorder_traversal(root,inorder);
        int s = 0,e = inorder.size()-1;
        int sum;
        while(s<e){
            sum = inorder[s]+inorder[e];
            cout<<sum<<endl;
            if(sum == k){
                return true;
            }
            if(sum<k){
                s++;
            }
            else{
                e--;
            }
        }
        return false;
    }
};