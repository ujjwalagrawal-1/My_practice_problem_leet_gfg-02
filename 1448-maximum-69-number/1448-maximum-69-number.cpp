
class Solution {
public:
    int maximum69Number (int num) {
        vector<int>vec;
        int j = 0;
        while(num != 0){
            vec.push_back(num % 10) ;
            num = num/10;
            j++;
        }
        reverse(vec.begin(),vec.end());
        int change = 0;
        for(int i = 0;i<vec.size();i++){
            if(vec[i] == 9){
                continue;
            }
            else{
                vec[i] = 9;
                break;
            }
        }
        num = 0;
        for(auto itr:vec){
            num = num*10 + itr;
        }
        vec.clear();
        return num;
    }
};