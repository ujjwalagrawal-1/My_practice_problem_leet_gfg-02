// class Solution {
// public:
//     int numberOfWays(string corridor) {
//         int xp = 0;
//         int sum = 0;
//         while(true){
//             int t = corridor.find("SS",xp);
//             if(t != string::npos){
//                 t += 2;int y = 0;
//                 while(corridor[t] != 'S' && t < corridor.size()){
//                     t++;
//                     y++;
//                 }
//                 y++;
//                 sum += y;
//                 xp = t;
//             }
//             else{
//                 int se = 0;
//                 if(corridor.length() > 1){
//                     for(auto itr:corridor){
//                         if(itr == 'S'){
//                             se++;break;
//                         }
//                     }
//                 }
//                 sum = xp == 0 && se ? 1:sum;
//                 break;
//             }
//         }
//         // if(sum = 0){
//         //     sum++;
//         // }
//         return sum;
//     }
// };

class Solution {
public:
    int mod = 1e9 + 7;
    
    int numberOfWays(string corridor) {
        vector<int> pos;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                pos.push_back(i);
            }
        }
        
        if (pos.size() % 2 || pos.size() == 0)
            return 0;
        
        long long ans = 1;
        int prev = pos[1];
        for (int i = 2; i < pos.size(); i += 2) {
            int length = pos[i] - prev;
            ans = (ans * length) % mod;
            
            prev = pos[i + 1];
        }
        
        return ans;
    }
};