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
// int No_Of_Element(TreeNode* root){
//     if(root == NULL){
//         return 0; 
//     }
//     int a = No_Of_Element(root->left);
//     int b = No_Of_Element(root->right);

//     return a+b+1;
// }
// void Solve(TreeNode* root,int &ans){
//     if(root == NULL){
//         return;
//     }

//     int Total_element = No_Of_Element(root);
//     cout<<"Total_element is   ->"<<Total_element<<endl;
//     int avg = root->val/Total_element;
//     cout<<"avg for   "<<root->val<<"->"<<avg<<endl;
//     if(avg == root->val){
//         ans++;
//     }
//     cout<<"ans is -->"<<ans<<endl;
//     Solve(root->left,ans);
//     Solve(root->right,ans);

// }

pair<int,int> Solve_tree(TreeNode* root,int &ans){
    if(root == NULL){
        return {0,0};
    }
    pair<int,int> a = Solve_tree(root->left,ans);
    // sum += root->val;
    // elements_traversed +=1;
    // if(root->val == sum/elements_traversed)ans++;
    pair<int,int> b = Solve_tree(root->right,ans);
    // sum += root->val;
    // elements_traversed +=1;
    // if(root->val == sum/elements_traversed)ans++;
    if(root->val == (a.first+b.first+root->val)/(a.second+b.second+1))ans++;
    return {a.first+b.first+root->val,a.second+b.second+1};
}
    int averageOfSubtree(TreeNode* root) {
        // int ans = 0;
        // int ans = 0;
        // Solve(root,ans);
        // return ans;

        int ans = 0;
        pair<int,int> pa = Solve_tree(root,ans);
        return ans;
    }
};