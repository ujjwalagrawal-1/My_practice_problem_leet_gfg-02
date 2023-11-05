class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = 0;
        for(auto x : arr)maxi = max(maxi, x);
        if(k > n)return maxi;

        unordered_map<int, int> m;

        deque<int> q;

        for(auto x : arr)q.push_back(x);

        while(!q.empty()){
            int a = q.front();
            q.pop_front();
            int b = q.front();
            q.pop_front();

            q.push_back(min(a, b));
            q.push_front(max(a, b));

            m[max(a, b)]++;

            if(m[max(a, b)] == k)return max(a,b);
        }

        return 0;
    }
};