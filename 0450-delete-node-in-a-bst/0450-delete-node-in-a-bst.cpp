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
int findmax(TreeNode* &root){
    TreeNode* temp = root;
    if(temp == NULL){
        return -1;
    }
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->val;
}
int findmin(TreeNode* &root){
    TreeNode* temp = root;
    if(temp == NULL){
        return -1;
    }
    while(root->left != NULL){
        temp = temp->left;
    }
    return temp->val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            if(root->right == NULL && root->left == NULL){
                return NULL;
            }
            if(root->left != NULL && root->right == NULL){
                TreeNode* child = root->left;
                return child;
            }
            if(root->left == NULL && root->right != NULL){
                TreeNode* child = root->right;
                return child;
            }
            if(root->left != NULL && root->right != NULL){
                int inorderpre = findmax(root->left);
                root->val = inorderpre;
                root->left = deleteNode(root->left,inorderpre);
                return root;
            }
        }
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};