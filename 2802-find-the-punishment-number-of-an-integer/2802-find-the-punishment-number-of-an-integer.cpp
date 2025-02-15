class Solution {
public:
    int f;
    bool ch(string str, int i, int cs) {
        if (i >= str.size()) {
            return cs == f;
        }
        bool ff = false;
        for (int st = i + 1; st <= str.size(); st++) {
            string su = str.substr(i, st - i);
            int v = stoi(su);
            cs += v;
            ff |= ch(str, st, cs);
            cs -= v;
        }
        return ff;
    }

    bool c(int n) {
        int val = n * n;
        f = n;
        string str = to_string(val);
        return ch(str, 0, 0);
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (c(i)) {
                ans += i*i;
            }
        }
        return ans;
    }
};