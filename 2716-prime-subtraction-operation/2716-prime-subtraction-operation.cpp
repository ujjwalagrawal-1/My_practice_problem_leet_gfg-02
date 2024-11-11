class Solution {
public:
vector<bool> isprime;
void Sieve(int n){
    isprime.assign(n+1,1);
    isprime[0] = isprime[1] = 0;
    for(int i = 2;i*i<=n;i++){
        if(isprime[i]){
            for(int j = i*i;j<=n;j+=i){
                isprime[j] = 0;
            }
        }
    }
}
    bool primeSubOperation(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        int maxi = *max_element(nums.begin(),nums.end());
        Sieve(maxi);
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                continue;
            }
            bool fl = 0;
            for(int j = nums[i]-nums[i+1]+1;j < nums[i];j++){
                if(isprime[j]){
                    nums[i] -= j;
                    fl = 1;
                    break;
                }
            }
            if(!fl){
                return false;
            }
        }
        return true; 
    }
};  