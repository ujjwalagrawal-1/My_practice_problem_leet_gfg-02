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
    void addNode(TreeNode* root, int val) {
        if (root->left == nullptr) {
            root->left = new TreeNode(val);
        } else {
            TreeNode* NewNode1 = new TreeNode(val);
            NewNode1->left = root->left;
            root->left = NewNode1;
        }
        
        if (root->right == nullptr) {
            root->right = new TreeNode(val);
        } else {
            TreeNode* NewNode2 = new TreeNode(val);
            NewNode2->right = root->right;
            root->right = NewNode2;
        }
    }

    void addrow(TreeNode* root, int val, int depth, int currlen) {
        if (root == nullptr) {
            return;
        }
        
        if (depth - 1 == currlen) {
            addNode(root, val);
            return;
        }
        
        addrow(root->left, val, depth, currlen + 1);
        addrow(root->right, val, depth, currlen + 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        addrow(root, val, depth, 1);
        return root;
    }
};
