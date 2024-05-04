class Solution {
private:
bool solver(int index,string s,unordered_set<string>&st,vector<int>&dp)
{
    if(index>=s.size())
    {
       return true;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    for(int i=index;i<s.length();i++)
    {
        string g=s.substr(index,i-index+1);
        if(st.find(g)!=st.end() && solver(i+1,s,st,dp))
        {
            return dp[index]=true;
        }
    }
   return dp[index]=false;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string>st(wordDict.begin(),wordDict.end());
         int n=s.length();
         vector<int>dp(n,-1);
         //bool ans=false;
         return solver(0,s,st,dp);
         //return ans;
    }
};