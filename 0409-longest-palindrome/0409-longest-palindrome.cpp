class Solution
{
    public:
        int longestPalindrome(string s)
        {
            map<char, int> hash;
            for (int i = 0; i < s.size(); i++)
            {
                hash[s[i]]++;
            }
            // int count = 0;
            // int maxi = INT_MIN;
            int x = 0;
            // int y = 0;
            for (auto itr: hash)
            {
                if (itr.second % 2 == 1)
                {
                    x += 1;
                }
            }
            if(x>1)
            return s.size()-x+1;
            return s.size();
        }
};