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
void f(vector<TreeNode*> &temp,TreeNode* &root,set<int> & st){
    if(root == NULL){
        return;
    }

    f(temp,root->left,st);
    f(temp,root->right,st);

    if(st.count(root->val)){
        if(root->left != NULL){
            temp.push_back(root->left);
        }
        if(root->right != NULL){
            temp.push_back(root->right);
        }
        root = NULL;
    }

}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& todelete) {
        vector<TreeNode*> temp;
        set<int>  st;
        for(auto  itr:todelete ){
            st.insert(itr);
        }
        f(temp,root,st);
        if (root && !st.count(root->val)) {
            temp.push_back(root);
        }
        return temp;
    }
};