struct Node{
    Node* links[26];
    bool end =  false;
};
class Solution {
public:
void insert(string word,Node* root){
    Node* temp = root;

    for(int i = 0;i<word.size();i++){
        if(!temp->links[word[i] - 'a']){
            temp->links[word[i] - 'a'] = new Node();
        }
        temp = temp->links[word[i] - 'a'];
    }
    temp->end = true;
}

bool f(string s,Node* root){
    Node* temp = root;
    for(int i = 0;i<s.size();i++){
        if(!temp->links[s[i] - 'a']){
            return false;
        }
        temp = temp->links[s[i] - 'a'];
        if(!temp->end){
            return false;
        }
    }
    return true;
}
    string longestWord(vector<string>& words) {
        Node* root = new Node();
        for(auto itr : words){
            insert(itr,root);
        }
        string longest = "";
        for(int i = 0;i<words.size();i++){
            if(words[i].size() >= longest.size() && f(words[i],root)){
                if(words[i].length() == longest.length()){
                    longest = min(longest,words[i]);
                }
                else{
                    longest = words[i];
                }
            }
        }
        return longest;
    }
};