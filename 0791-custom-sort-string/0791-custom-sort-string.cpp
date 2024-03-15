
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> arr(26, 0);

        for (char c : s)
            arr[c - 'a']++;

        string ss = "";

        for (char c : order) {
            while (arr[c - 'a']-- > 0)
                ss += c;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            while (arr[c - 'a']-- > 0)
                ss += c;
        }

        return ss;
    }

    
};