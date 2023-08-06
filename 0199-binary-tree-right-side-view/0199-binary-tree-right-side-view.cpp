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
void right_traversal(TreeNode* &root,vector<int>& answer,int len){
    if(root == NULL){
        return;
    }
    if(len == answer.size())
    answer.push_back(root->val);
    right_traversal(root->right,answer,len+1);
    right_traversal(root->left,answer,len+1);

}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>answer;
        int len = 0;
        right_traversal(root,answer,len);
        return answer;
    }
};