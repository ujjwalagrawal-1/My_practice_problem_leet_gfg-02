struct Node{
    Node* links[26] = {NULL};
    bool isEnd = false;
};
class StreamChecker {
    private:
    Node* root;
    string stream = "";
public:
    StreamChecker(vector<string>& words) {
        root = new Node();
        for(int i = 0;i<words.size();i++){
            Node* temp = root;
            for(int j = words[i].size()-1;j>=0;j--){
                if(!temp->links[words[i][j]-'a']){
                    temp->links[words[i][j]-'a'] = new Node();
                }
                temp = temp->links[words[i][j]-'a'];
            }
            temp->isEnd = true;
        }
    }
    
    bool query(char letter) {
        stream += letter;
        Node* temp = root;
        for (int i = stream.size() - 1; i >= 0; --i) {
            if (!temp->links[stream[i] - 'a']) {
                return false;
            }
            temp = temp->links[stream[i] - 'a'];
            if (temp->isEnd) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */