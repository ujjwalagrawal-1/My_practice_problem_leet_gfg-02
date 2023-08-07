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
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int,vector<int>>answer;
//         queue<pair<TreeNode*,int>>q;
//         q.push({root,0});
//         while(!q.empty()){
//             pair<TreeNode*,int>check = q.front();
//             int hd = check.second;
//             TreeNode* temp = check.first;
//             answer[hd].push_back(temp->val);
//             if(temp->left)
//             q.push({temp->left,hd-1});
//             if(temp->right)
//             q.push({temp->right,hd+1});
//             q.pop();
//         }
//         vector<vector<int>>a;
//         for(auto itr:answer){
//             // sort(itr.second.begin(),itr.second.end());
//             a.push_back(itr.second);
//         }
//         return a;
//     }
// };

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int> > > nodes;

        queue<pair<TreeNode*,pair<int,int> > > q;

        vector<vector<int> > ans;

        if(root==NULL){
            return ans;
        }
        q.push({root,{0,0}});
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int> > temp=q.front();
            q.pop();
            TreeNode* frontNode=temp.first;
            int hd=temp.second.first;
            int level=temp.second.second;

            nodes[hd][level].insert(frontNode->val);

            if(frontNode->left){
                q.push({frontNode->left,{hd-1,level+1}});
            }

            if(frontNode->right){
                q.push({frontNode->right,{hd+1,level+1}});
            }
        }
        for(auto i:nodes){
            vector<int> res;
            for(auto j:i.second){
                for(auto k:j.second){
                    res.push_back(k);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};