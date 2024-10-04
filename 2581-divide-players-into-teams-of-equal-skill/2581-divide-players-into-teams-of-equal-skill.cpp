class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans = 0;
        int i = 0,j = skill.size()-1;
        int prev = skill[i] + skill[j];
        while(i < j){
            if(skill[i] + skill[j] != prev){
                return -1;
            }
            else{
                ans += 1ll*skill[i]*skill[j];
            }
            i++;
            j--;
        }
        return ans;
    }
};