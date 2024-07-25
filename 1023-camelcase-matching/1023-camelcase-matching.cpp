struct Node{
    Node* links[256];
    bool flag = false;

    bool ispossible(char ch){
        return links[ch] != NULL;
    }
    Node* get(char ch){
        return links[ch];
    }
    void put(char ch,Node* node){
        links[ch] = node;
    }
    bool islast(){
        return flag;
    }
    void setlast(){
        flag = true;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* temp = root;
        for(int i = 0;i<word.size();i++){
            temp->put(word[i],new Node());
            temp = temp->get(word[i]);
        }
        temp->setlast();
    }
    bool check(string word){
        Node* temp = root;
        for(int i = 0;i<word.size();i++){
            if(temp->ispossible(word[i])){
                temp = temp->get(word[i]);
            }
            else if(isupper(word[i])){
                return false;
            }
        }
        return temp->islast();
    }
};
class Solution {
public:
    vector<bool> camelMatch(vector<string>& q, string pattern) {
        vector<bool> veci;
        Trie trie;
        trie.insert(pattern);
        for(auto itr:q){
            veci.push_back(trie.check(itr));
        }
        return veci;
    }
};