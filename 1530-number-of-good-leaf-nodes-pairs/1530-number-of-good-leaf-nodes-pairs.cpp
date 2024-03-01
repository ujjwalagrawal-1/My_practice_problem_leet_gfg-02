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
vector<int> solve(TreeNode* &root,int distance,int & cnt){
    if(root == NULL){
        return {};
    }
    if(root->left == 0 && root->right == 0){
        return {1};
    }

    vector<int> lft = solve(root->left,distance,cnt);
    vector<int> rgt = solve(root->right,distance,cnt);

    for(auto itr:lft){
        for(auto i:rgt){
            if(itr+i <= distance){
                cnt++;
            }
        }
    }
    vector<int> veci;
    for(auto itr:lft){
        if(itr+1 < distance){
            veci.push_back(itr+1);
        }
    }
    for(auto itr:rgt){
        if(itr+1 < distance){
            veci.push_back(itr+1);
        }
    }

    return veci;
}
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        solve(root,distance,cnt);
        return cnt;
    }
};