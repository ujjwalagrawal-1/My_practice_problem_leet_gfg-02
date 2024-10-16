class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        string ans = "";
        if(a > 0)
        pq.push({a,'a'});
        if(b > 0)
        pq.push({b,'b'});
        if(c > 0)
        pq.push({c,'c'});

        while(!pq.empty()){
            // cout<<"ans is  "<<ans<<endl;
            if(pq.top().first == 0){
                break;
            }
            if(ans.size() >= 2){
                pair<int,char> store;
                bool fl = 0;
                if(ans[ans.size()-1] == pq.top().second && ans[ans.size()-2] == pq.top().second){
                    store = pq.top();
                    pq.pop();
                    fl = 1;
                }
                if(pq.empty()){
                    return ans;
                }
                if(pq.top().first  >= 1){
                    ans += pq.top().second;
                    int val = pq.top().first;
                    char ch = pq.top().second;
                    pq.pop();
                    if(val-1 > 0)
                    pq.push({val-1,ch});
                }
                if(fl){
                    pq.push(store);
                }
            }
            else{
                if(pq.top().first  >= 1){
                    ans += pq.top().second;
                    int val = pq.top().first;
                    char ch = pq.top().second;
                    pq.pop();
                    if(val-1 > 0)
                    pq.push({val-1,ch});
                }
            }
        }
        return ans;
    }
};