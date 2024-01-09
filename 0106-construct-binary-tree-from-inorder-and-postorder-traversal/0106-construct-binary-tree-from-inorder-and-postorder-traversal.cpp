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
int findindex(vector<int> &inorder,int &x){
    for(int i = 0;i<inorder.size();i++){
        if(inorder[i] == x){
            return i;
        }
    }
    return -1;
}
TreeNode* make_tree(vector<int> &inorder,vector<int> &postorder,int inorder_start,int inorder_end,int &post_order_index){
    //base condition
    if(inorder_start>inorder_end || post_order_index < 0){
    return NULL;
    }
    //mane function
    int ind = findindex(inorder,postorder[post_order_index--]);
    TreeNode* root = new TreeNode(inorder[ind]);
    root->right = make_tree(inorder,postorder,ind+1,inorder_end,post_order_index);
    root->left = make_tree(inorder,postorder,inorder_start,ind-1,post_order_index);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorder_start = 0;
        int inorder_end = inorder.size()-1;
        int post_order_index = postorder.size()-1;
        return make_tree(inorder,postorder,inorder_start,inorder_end,post_order_index);
    }
};