class Solution {
public:

    int minimumOperationsToMakeEqual(int x, int y) {
        // Pure BFS Approch 

        if(y >= x){
            return y - x;
        }
        queue<pair<int,int>> q;
        q.push({x,0});
        unordered_set<int> st;

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int val = p.first;
            int opt = p.second;
            if(st.count(val)){
                continue;
            }

            st.insert(val);
            if(val == y){
                return  opt;
            }
            if(val%11 == 0){
                q.push({val/11,opt+1});
            }
            if(val%5 == 0){
                q.push({val/5,opt+1});
            }
            q.push({val + 1,opt+1});
            q.push({val-1,opt+1});
        }
        return 0;
    }
};
