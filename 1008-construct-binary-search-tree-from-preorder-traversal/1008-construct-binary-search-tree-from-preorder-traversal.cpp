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
// int locate(vector<int> &veci,int t){
//     for(int i = 0;i<veci.size();i++){
//         if(veci[i] == t){
//             return i;
//         }
//     }
//     return -1;
// }
// TreeNode* f(vector<int> &inorder,vector<int> &preorder,int in_st,int in_end,int pre_ind){
//     if(in_st>in_end || pre_ind >= inorder.size()){
//         return NULL;
//     }
//     int ele = preorder[pre_ind];
//     TreeNode* newnode = new TreeNode(ele);
//     int find = locate(inorder,ele);
//     newnode->left = f(inorder,preorder,in_st,find-1,pre_ind++);
//     newnode->right = f(inorder,preorder,find+1,in_end,pre_ind++);
//     return newnode;
// }
int position(vector<int>& Inorder,int size,int element){
  for(int i = 0;i<size;i++){
    if(Inorder[i] == element){
      return i;
    }
  }
  return -1;
}
TreeNode* Buiding_tree_pre_and_In(vector<int> Preorder,vector<int> Inorder,int Infirst,int Inlast,int &prefirst,int size){
  if(Infirst>Inlast || prefirst >= size){
    return NULL;
  }
  int element = Preorder[prefirst++];
  TreeNode* root = new TreeNode(element);
  int pos = position(Inorder,size,element);
  root->left = Buiding_tree_pre_and_In(Preorder,Inorder,Infirst,pos-1,prefirst,size);
  root->right = Buiding_tree_pre_and_In(Preorder,Inorder,pos+1,Inlast,prefirst,size);
  return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int Infirst = 0;
  int prefirst = 0;
  int size = preorder.size();
  int Inlast = size-1;
  TreeNode* root = Buiding_tree_pre_and_In(preorder,inorder,Infirst,Inlast,prefirst,size);
  return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        // int in_st = 0;
        // int in_end = preorder.size()-1;
        // return f(inorder,preorder,in_st,in_end,0);
        return buildTree(preorder,inorder);
    }
};