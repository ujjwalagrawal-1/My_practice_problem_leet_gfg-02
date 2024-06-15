class Solution {
public:
    long long countVowels(string word) {
        
        long long n = word.size(),ans = 0;
        vector<int> pos;
        
        for(int i = 0;i<word.size();i++)
        {
          if(word[i] =='a' ||word[i]=='i' || word[i]=='o' || word[i]=='e'|| word[i]=='u')
          {
            long long left = i,right = n-i-1;
            ans+=(left+right+left*right+1);
          }  
        }
        return ans;
    }
};