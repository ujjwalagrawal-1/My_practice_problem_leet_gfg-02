class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        
        while(n != 1){
            int x = n;
            int sum = 0;
            while(x != 0){
                sum += pow(x%10,2);
                x/=10;
            }
            if(s.find(sum) != s.end())return false;
            else s.insert(sum);
            n = sum;
        }
        return true;
    }
};