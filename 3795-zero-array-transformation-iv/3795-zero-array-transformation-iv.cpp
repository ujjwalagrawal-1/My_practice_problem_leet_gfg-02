class Solution {
public:
    int dp[1001][1001];

    bool check(int ind, int num, vector<vector<int>> &q, int i, int k) {
        if (num == 0) return 1;
        if (i >= k) return 0;
        if (num < 0) return 0;

        if (dp[i][num] != -1) {
            return dp[i][num];
        }

        bool ans = 0;
        if (ind < q[i][0] || ind > q[i][1]) {
            // cout<<"Increment at i = "<<i<<endl;
            ans |= check(ind, num, q, i + 1, k);
        }
        else {
            // cout<< "call from i = "<<i<<" to f = ("<<num-q[i][2]<<" , "<<i+1<<") , ("<<num<<" , "<<i+1<<")"<<endl;
            ans |= check(ind, num - q[i][2], q, i + 1, k) | check(ind, num, q, i + 1, k);
        }

        return dp[i][num] = ans;
    }

    bool f(int mid, vector<int> &nums, vector<vector<int>> &q) {
        for (int i = 0; i < nums.size(); i++) {
            memset(dp, -1, sizeof(dp));
            bool fl = check(i, nums[i], q, 0, mid);
            // cout<<"flag for i = "<<i<<" is fl  = "<<fl<<endl;
            if (!fl) {
                return 0;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int s = 0, e = q.size();
        while (s <= e) {
            int mid = s + (e - s) / 2;
            // cout<<"current start, end and mid is "<<s<< " "<<e<<" "<<mid<<endl;
            if (f(mid, nums, q)) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        if(s > q.size())return -1;
        return s;
    }
};
