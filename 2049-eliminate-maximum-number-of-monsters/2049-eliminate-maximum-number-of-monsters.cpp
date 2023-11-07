class Solution {
public:
    int eliminateMaximum(vector<int>& D, vector<int>& S) {
        vector<int> P;
        for(int i=0;i<D.size();i++) P.push_back(ceil((float)D[i]/(float)S[i]));
        int sum=1;
        sort(P.begin(),P.end());
        for(int i=1;i<P.size();i++){
            if(sum>=P[i]) break;
              sum+=1;
        }
        return sum;
    }
};