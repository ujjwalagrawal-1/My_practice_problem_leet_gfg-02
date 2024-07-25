class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        unordered_set<string> s1(words.begin(),words.end());

        for(auto itr: st){
            for(int i = 1;i<itr.size();i++){
                string a = itr.substr(i);
                if(s1.count(a)){
                    s1.erase(a);
                }
            }
        }
        int ans = 0;
        for(auto itr:s1){
            ans += itr.size();
            ans += 1;
        }

        return ans;
    }
};