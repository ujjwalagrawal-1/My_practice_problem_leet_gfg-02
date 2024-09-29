class Solution {
public:
bool is(char &ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    }
    return false;
}
long long f(string word,int k){
    vector<int> f(26,0);
    long long ans = 0;
    int i = 0,j = 0;
    long long cnt = 0;
    while(j < word.size()){
        if(is(word[j])){
            f[word[j] - 'a']++;
        }
        else if(!is(word[j])){
            cnt++;
        }
        while(i<=j && cnt >= k && f[int('a' - 'a')] > 0 && f[int('e' - 'a')] > 0 && f[int('i' - 'a')] > 0  && f[int('o' - 'a')] > 0 && f[int('u' - 'a')] > 0){
            ans += (word.size() - j);
            if(is(word[i])){
                f[word[i] - 'a']--;
            }
            else if(!is(word[i])){
                cnt--;
            }
            i++;
        }
        j++;
    }

    return ans;
}
    long long countOfSubstrings(string word, int k) {
        return f(word,k) - f(word,k+1);
    }
};