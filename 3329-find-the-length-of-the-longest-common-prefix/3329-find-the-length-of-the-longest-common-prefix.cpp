class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string,int> mp1;
        map<string,int> mp2;
        for(int i = 0;i<arr1.size();i++){
            mp1[to_string(arr1[i])]++;
        }

        for(int i = 0;i<arr2.size();i++){
            mp2[to_string(arr2[i])]++;
        }
        int maxi = INT_MIN;
        for(int i = 0;i<arr1.size();i++){
            string temp = "";
            string move = to_string(arr1[i]);
            for(int j = 0;j<move.size();j++){
                temp += move[j];
                if(mp2[temp] != 0){
                    maxi = max(maxi,j+1);
                }
                else{
                    break;
                }
            }
        }
        for(int i = 0;i<arr2.size();i++){
            string temp = "";
            string move = to_string(arr2[i]);
            for(int j = 0;j<move.size();j++){
                temp += move[j];
                if(mp1[temp] != 0){
                    maxi = max(maxi,j+1);
                }
                else{
                    break;
                }
            }
        }

        return maxi == INT_MIN ? 0 : maxi;
    }
};