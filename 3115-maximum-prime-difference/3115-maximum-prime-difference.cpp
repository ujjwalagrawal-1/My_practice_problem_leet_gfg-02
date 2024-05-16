class Solution {
public:
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
    int maximumPrimeDifference(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            if(isPrime(nums[i])){
                break;
            }
            i++;
        }
        int j = nums.size()-1;
        while(j >= 0){
            if(isPrime(nums[j])){
                break;
            }
            j--;
        }
        if(j-i >= 0){
            return j-i;
        }
        else{
            return 0;
        }
    }
};