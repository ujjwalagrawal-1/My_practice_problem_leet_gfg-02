class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(int i = 0;i<rolls.size();i++){
            sum += rolls[i];
        }
        int mul = (rolls.size()  + n)*mean;
        int diff = mul - sum;
        if(n*6 < diff || diff < n){
            return  {};
        }
        int rem = diff%n;
        int q = diff/n;

        vector<int> veci(n,q);
        for(int i = 0;i<rem;i++){
            veci[i]++;
        }

        return veci;
    }
};