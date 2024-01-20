#define M 1000000007

class Solution {
public:
    vector<int> prevlowest(vector<int>& arr) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> Nextlowest(vector<int>& arr) {
        stack<int> s;
        s.push(arr.size());
        vector<int> ans(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != arr.size() && arr[s.top()] > curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> vecx = prevlowest(arr);
        vector<int> vecy = Nextlowest(arr);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long a = i - vecx[i];
            long long b = vecy[i] - i;

            ans += (arr[i] * a * b) % M;
            ans %= M;
        }
        return ans;
    }
};