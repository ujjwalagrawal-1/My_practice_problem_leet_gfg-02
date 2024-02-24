class Solution {
public:
    string arrangeWords(string text) {
        // vector<pair<int,string>> veci;
        map<int,vector<string>> mp;
        for(int i = 0;i<text.size();i++){
            string str = "";
            while(i<text.size() && text[i] != ' '){
                str += text[i];
                i++;
            }
            if(str[0]<= 90 && str[0]>= 65){
                str[0] += 32;
            }
            mp[str.size()].push_back(str);
        }
        text = "";
        for(auto itr:mp){
            for(auto i:itr.second){
                text += i;
                text += " ";
            }
            
        }
        text.pop_back();
        text[0] -= 32;
        return text;
    }
};