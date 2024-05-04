class Solution {
public:
bool fn(unordered_set<string> &st,int i,int j,string &s,string temp,map<string,bool> &mp){

    bool a = false,b = false;
    if(mp.count(temp)){
        return mp[temp];
    }
    while(i<s.size()){
        temp += s[i];
        if(i == s.size()-1){
            if(st.count(temp)){
                return true;
            }
            else{
                return false;
            }
        }
        if(st.count(temp)){
            a = fn(st,i+1,j,s,temp,mp);
            b = fn(st,i+1,i+1,s,"",mp);
            return mp[temp] = a | b;
        }
        i++;
    }
    return 0;
}
    bool wordBreak(string s, vector<string>& wd) {
        unordered_set<string>  st;
        map<string,bool> mp;
        for(auto itr: wd){
            st.insert(itr);
        }
       return fn(st,0,0,s,"",mp);
    }
};