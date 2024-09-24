struct Node{
    Node* links[10];
};
class Solution {
public:
void createTrie(vector<int> &arr1,Node* &root){
    for(auto itr : arr1){
        Node* temp = root;
        string r = to_string(itr);
        for(int i = 0;i<r.size();i++){
            if(temp->links[r[i] - '0'] == NULL){
                temp->links[r[i] - '0'] = new Node();
            }
            temp = temp->links[r[i] - '0'];
        }
    }
}
int traverse_find_the_Max(Node* a,Node* b){
    int maxi = 0;
    for(int i = 0;i<10;i++){
        if(a->links[i] && b->links[i]){
            maxi = max(maxi,traverse_find_the_Max(a->links[i],b->links[i]) + 1);
        }
    }
    return maxi;
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node* a = new Node();
        Node* b = new Node();
        //  CREATED Trie 
        createTrie(arr1,a);
        createTrie(arr2,b);
        // Now Search inside the Trie;
        return traverse_find_the_Max(a,b);
    }
};