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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int flag = 0;
        // int brk = 0;
        while(!qu.empty()){
            int sz = qu.size();
            flag = flag ? 0:1;
            int prev = flag ? INT_MIN:INT_MAX;
            for(int i = 0;i<sz;i++){
                TreeNode* temp = qu.front();
                // cout<<temp->val<<" ";
                qu.pop();
                if(flag == 1){
                    //even level and containing odd value in strictly increasing order 
                    if(prev >= temp->val || temp->val%2 == 0){
                        // cout<<endl;
                        // cout<<"break 1";
                        return false;
                    }
                }
                else if(flag == 0){
                    if(prev <= temp->val || temp->val%2 == 1){
                        // cout<<endl;
                        // cout<<"break 0";
                        return false;
                    }
                }
                prev = temp->val;
                if(temp->left){
                    qu.push(temp->left);
                }
                if(temp->right){
                    qu.push(temp->right);
                }
            }
            cout<<endl;
        }
        return true;
    }
};