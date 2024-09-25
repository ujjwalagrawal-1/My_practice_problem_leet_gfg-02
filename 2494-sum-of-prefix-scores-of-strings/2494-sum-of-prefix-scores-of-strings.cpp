struct Node{
    Node* links[26];
    int cnt = 0;
    bool flag = false;
};
class Solution {
public:
    void insert(string st,Node* root){
        Node* temp = root;
        for(int i = 0;i<st.size();i++){
            if(!temp->links[st[i]-'a']){
                temp->links[st[i]-'a'] = new Node();
            }
            temp = temp->links[st[i] - 'a'];
            temp->cnt++;
        }
        temp->flag = true;
    }
    int find(Node* root,string st){
        int tt = 0;
        Node* temp = root;
        for(int i = 0;i<st.size();i++){
            temp = temp->links[st[i]-'a'];
            tt += temp->cnt;
        }
        return tt;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();
        vector<int> ans;
        for(int i = 0;i<words.size();i++){
            insert(words[i],root);
        }
        for(int i = 0;i<words.size();i++){
            ans.push_back(find(root,words[i]));
        }

        return ans;
    }
};