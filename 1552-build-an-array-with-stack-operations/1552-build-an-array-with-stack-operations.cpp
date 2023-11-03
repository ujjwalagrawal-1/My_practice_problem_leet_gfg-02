class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> veci;
        // for(auto itr:target){
        //     veci[itr-1] = true;
        // }
        // vector<string> vs;
        // for(auto itr:veci){
        //     if(itr){
        //         vs.push_back("Push");
        //     }
        //     else{
        //         vs.push_back("Push");
        //         vs.push_back("Pop");
        //     }
        // }/


        // return vs;

        vector<int> sample;
        int y = 1;
        int i = 0;
        while(sample != target){
            if(y != target[i]){
                veci.push_back("Push");
                veci.push_back("Pop");
                y++;
            }
            else{
                veci.push_back("Push");
                sample.push_back(y);
                y++;i++;
            }
        }
        return veci;
    }
};