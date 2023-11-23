class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<int> ques = nums;
        vector<bool> ans(l.size(),true);
        for(int i = 0;i<l.size();i++){
            sort(ques.begin()+l[i],ques.begin()+r[i]+1);
            // for(auto itr:ques){
            //     cout<<itr<<" ";
            // }
            // cout<<endl;
            int diff = ques[l[i]]-ques[l[i]+1];
            // cout<<"diff for the" <<i+1<<" is "<<diff<<endl;
            for(int j = l[i];j<r[i];j++){
                // cout<<"minus for the j " <<j<<" is "<<ques[j]-ques[j+1]<<endl;
                if(diff != ques[j]-ques[j+1]){
                    ans[i] = false;
                    break;
                }
            }
            ques = nums;
        }
        return ans;
    }
};