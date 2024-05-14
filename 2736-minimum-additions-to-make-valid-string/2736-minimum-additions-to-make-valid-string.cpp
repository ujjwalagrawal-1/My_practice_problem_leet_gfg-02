class Solution {
public:
    int find(int i,string& word,int n,vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini=INT_MAX;
        if(word[i]=='a'){
            if(i+1<n && word[i+1]=='a'){
                mini=2+find(i+1,word,n,dp);
            }else if(i+1<n && word[i+1]=='b'){
                mini=find(i+1,word,n,dp);
            }else if(i+1<n && word[i+1]=='c'){
                mini=1+find(i+1,word,n,dp);
            }
            else mini=2+find(i+1,word,n,dp);
        }else if(word[i]=='b'){
            
            if(i+1<n && word[i+1]=='a'){
                mini=1+find(i+1,word,n,dp);
            }else if(i+1<n && word[i+1]=='b'){
                mini=2+find(i+1,word,n,dp);
            }else if(i+1<n && word[i+1]=='c'){
                mini=find(i+1,word,n,dp);
            }else mini=1+find(i+1,word,n,dp);
            if(i==0){
                mini++;
            }
        }
         else if(word[i]=='c'){
             
             if(i+1<n && word[i+1]=='a'){
                mini=find(i+1,word,n,dp);
            }else if(i+1<n && word[i+1]=='b'){
                mini=1+find(i+1,word,n,dp);
            }else if(i+1<n && word[i+1]=='c'){
                mini=2+find(i+1,word,n,dp);
            }
             else   mini=find(i+1,word,n,dp);
             if(i==0){
                mini++;
                mini++;
             }
         }
        return dp[i] = mini;
        
    }
    int addMinimum(string word) {
        int n=word.size();
        vector<int> dp(n,-1);
        return find(0,word,n,dp);
    }
};