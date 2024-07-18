class Solution {
public:
    string removeKdigits(string nums, int k) {
        string st = "";
        for(int i = 0;i<nums.size();i++){
            if(st == ""){
                st += nums[i];
            }
            else{
                while(st != "" && st.back() > nums[i] && k){
                    st.pop_back();
                    k--;
                }
                st += nums[i];
            }
        }
        while(k){
            st.pop_back();
            k--;
        }
        if(st == ""){
            return "0";
        }
        int i = 0;
        while(i<st.size() && st[i] == '0'){
            i++;
        }
        if(i == st.size()){
            return st;
        }
        return st.substr(i);
    }
};