class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1;i<=9;i++){
        int num = i;
        int next = i+1;
        while(num<=high && next <= 9){
            num *= 10;
            num += next;
            
            if(num<=high && num>= low)
            ans.push_back(num);
            next++;
        }
        
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};