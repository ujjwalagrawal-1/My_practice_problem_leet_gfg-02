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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> vec;
        if(root == NULL){
            return vec;
        }
        queue<TreeNode*> q;
        bool lefttoright = true;
        q.push(root);
        while(!q.empty()){
            
            int size = q.size();
            vector<int> part(size);
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();q.pop();
                int index = lefttoright ? i : size -1 -i;
                part[index] = temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            vec.push_back(part);
            lefttoright = !lefttoright;
        }
        return vec;
    }
};