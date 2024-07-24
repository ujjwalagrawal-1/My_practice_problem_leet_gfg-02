struct Node{
    Node* links[10] = {NULL};
    bool flag = false;
    bool ispresent(char ch){
        return links[ch - '0'] != NULL;
    }
    void put(char ch,Node* node){
        links[ch - '0'] = node;
    }
    Node* get(char ch){
        return links[ch - '0'];
    }
    void setend(){
        flag = 1;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i =0;i<word.size();i++){
            if(!temp->ispresent(word[i])){
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setend();
    }
};
void traverseTrie(Node* node,int n,vector<int> &ans){
        if(node == NULL){
            return;
        }
        if(node->flag){
            ans.push_back(n);
        }
        for(char ch = '0';ch <= '9';ch++){
            if(node->ispresent(ch)){
                traverseTrie(node->get(ch),(n*10) + (ch - '0'),ans);
            }
        }
}
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // vector<int> ans;
        Trie trie;
        for(int i = 1;i<=n;i++){
            trie.insert(to_string(i));
        }
        vector<int> ans;
        traverseTrie(trie.root,0,ans);
        return ans;
    }
};