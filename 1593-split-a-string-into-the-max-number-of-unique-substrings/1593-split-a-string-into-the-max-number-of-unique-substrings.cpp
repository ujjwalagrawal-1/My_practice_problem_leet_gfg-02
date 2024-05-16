class Solution {
public:
    void f(int ind, string& s, int& cnt, int n, set<string>& st){
        if(ind==n){
            cnt=max(cnt, (int)st.size());
            return;
        }

        string temp="";
        for(int i=ind;i<n;i++){
            temp+=s[i];
            if(st.find(temp)==st.end()){
                st.insert(temp);
                f(i+1,s,cnt,n,st);
                st.erase(temp);
            }
        }
    }

    int maxUniqueSplit(string s) {
        int n=s.length();
        set<string>st;
        int cnt=0;
        f(0, s, cnt, n, st);
        return cnt;
    }
};