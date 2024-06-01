class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int numOnes = 0, ans = 0, prev = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
            {
                ans = max(prev, i - numOnes); 
                numOnes++;
                if(ans)
                    prev = ans + 1;
            }
        }
        return ans;
    }
};