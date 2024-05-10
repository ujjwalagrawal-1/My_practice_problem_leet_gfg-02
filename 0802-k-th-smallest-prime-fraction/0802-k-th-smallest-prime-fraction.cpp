class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, r = 1, m;
        vector<int> res;
        while (l <= r) {
            m = (l + r) / 2;
            int j = 1, total = 0, numerator = 0, denominator = 0;
            double maxFraction = 0;
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] > arr[j] * m) ++ j;
                total += n - j;
                if (j < n && maxFraction < arr[i] * 1.0 / arr[j]) {
                    maxFraction = arr[i] * 1.0 / arr[j];
                    numerator = i; denominator = j;
                }
            }
            if (total == k) {
                res = {arr[numerator], arr[denominator]};
                break;
            }
            if (total > k) r = m;
            else l = m;
        }
        return res;
    }
};