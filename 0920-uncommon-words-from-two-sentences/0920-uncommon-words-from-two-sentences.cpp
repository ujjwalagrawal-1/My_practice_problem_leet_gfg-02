class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> st1;
        map<string,int> st2;
        vector<string> ans;
        for(int i = 0;i<s1.size();i++){
            int j = i;
            while(j< s1.size() && s1[j] != ' '){
                j++;
            }
            st1[s1.substr(i,j-i)]++;
            i = j;
        }
        for(int i = 0;i<s2.size();i++){
            int j = i;
            while(j< s2.size() && s2[j] != ' '){
                j++;
            }
            st2[s2.substr(i,j-i)]++;
            i = j;
        }
        for(auto itr : st1){
            if(itr.second == 1){
                if(!st2.count(itr.first)){
                    ans.push_back(itr.first);
                }
            }
        }
        for(auto itr : st2){
            if(itr.second == 1){
                if(!st1.count(itr.first)){
                    ans.push_back(itr.first);
                }
            }
        }

        return ans;
    }
};