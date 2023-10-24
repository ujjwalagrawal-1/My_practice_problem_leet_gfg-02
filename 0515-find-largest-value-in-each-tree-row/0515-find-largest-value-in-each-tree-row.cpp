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
    vector<int> largestValues(TreeNode* root) {
        vector<int>answer;
        if(root == NULL){
            return answer;
        }
        queue<TreeNode*>q;
        int x = INT_MIN;
        q.push(root);
        while(!q.empty()){
            int x = INT_MIN;
            int length = q.size();
            for(int i = 0;i<length;i++){
                TreeNode* temp = q.front();
                x = max(x,temp->val);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            answer.push_back(x);
        }
        return answer;
    }
};