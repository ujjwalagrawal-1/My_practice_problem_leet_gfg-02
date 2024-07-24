struct Node{
    Node* links[256] = {NULL};
    bool flag = false;

    bool ispresent(char ch){
        return links[ch] != NULL;
    }
    void put(char ch,Node* node){
        links[ch] = node;
    }
    Node* get(char ch){
        return links[ch];
    }
    void setend(){
        flag = 1;
    }
    bool isend(){
        return flag;
    }
};
class Trie{
    private:
        Node* root;
    public:
    Trie(){
        root = new Node();
    }

    bool insert(string f){
        Node* temp = root;
        for(int i = 0;i<f.size();i++){
            if(!temp->ispresent(f[i])){
                temp->put(f[i],new Node());
            }
            temp = temp->get(f[i]);
            if(temp->isend() && f[i+1] == '/'){
                return false;
            }
        }
        temp->setend();
        return true;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        Trie trie;
        vector<string> ans;
        for(int i = 0;i<folder.size();i++){
            if(trie.insert(folder[i])){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};