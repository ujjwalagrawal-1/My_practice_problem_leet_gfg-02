struct Node{
    Node* links[26] = {NULL};
    bool flag = false;
    bool ispresent(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch  -'a'];
    }
    void setend(){
        flag = 1;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
    private:
    Node* root;
public:

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
    
    bool search(string word) {
        Node* temp = root;
        for(int i = 0;i<word.size();i++){
            if(!temp->ispresent(word[i])){
                return false;
            }
            if(temp->isend()){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return temp->isend();
    }
    
    bool startsWith(string word) {
        Node* temp = root;
        for(int i = 0;i<word.size();i++){
            if(!temp->ispresent(word[i])){
                return false;
            }
            if(temp->isend()){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */