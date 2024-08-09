struct Node{
    Node* links[26];
    int score = 0;
};
class MapSum {
public:
    Node* root;
    unordered_map<string,int> mp;
    MapSum() {
        root = new Node();
    }
    void insert(string key, int val) {
        Node* temp = root;
        int nval = val;
        if(mp.count(key)){
            val -= mp[key];
        }
        for(int i = 0;i<key.size();i++){
            if(!temp->links[key[i] - 'a']){
                temp->links[key[i]-'a'] = new Node();
            }
            temp = temp->links[key[i] - 'a'];
            temp->score += val;
        }
        mp[key] = nval;
    }
    
    int sum(string prefix) {
        Node* temp = root;
        for(int i = 0;i<prefix.size();i++){
            if(!temp->links[prefix[i] - 'a']){
                return 0;
            }
            temp = temp->links[prefix[i] - 'a'];
        }
        return temp->score;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */