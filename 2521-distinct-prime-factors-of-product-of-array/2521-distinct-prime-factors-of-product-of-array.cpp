class Solution {
public:
    vector<bool> primes;
    vector<int> hp;

    void Sieve(int n) {
        primes.assign(n + 1, true);
        hp.assign(n + 1, 0);
        primes[0] = primes[1] = false;

        for (int i = 2; i <= n; i++) {
            if (primes[i]) {
                hp[i] = i;
                for (int j = i * 2; j <= n; j += i) {
                    primes[j] = false;
                    if (hp[j] == 0) {
                        hp[j] = i;
                    }
                }
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        if (nums.empty()) return 0;

        int max_num = *max_element(nums.begin(), nums.end());
        Sieve(max_num);

        unordered_set<int> distinct_primes;

        for (int num : nums) {
            while (num > 1) {
                int pf = hp[num];
                distinct_primes.insert(pf);
                while (num % pf == 0) {
                    num /= pf;
                }
            }
        }

        return distinct_primes.size();
    }
};
