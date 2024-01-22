/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void level_order_traversal(Node* &root,vector<vector<int>> &veci){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> temp;
        for(int i = 0;i<n;i++){
            Node* root = q.front();q.pop();
            temp.push_back(root->val);
            for(auto itr:root->children){
                q.push(itr);
            }
        }
        veci.push_back(temp);
    }
}
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> veci;
        level_order_traversal(root ,veci);
        return veci;
    }
};