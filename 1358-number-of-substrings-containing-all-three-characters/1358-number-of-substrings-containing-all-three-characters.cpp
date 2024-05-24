#include <unordered_map>
#include <string>

class Solution {
public:
    long long numberOfSubstrings(std::string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int i = 0, j = 0;
        long long count = 0;

        while (j < n) {
            mp[s[j]]++;
            
            while (mp.size() == 3) {
                count += (n - j);
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
};
