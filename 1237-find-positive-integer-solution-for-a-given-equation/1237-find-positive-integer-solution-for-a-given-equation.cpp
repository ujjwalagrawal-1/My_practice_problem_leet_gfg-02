class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for(int x=1; x<=z; x++)
        {
            int b = 1, e = z;
            while(b<=e)
            {
                int m = b+(e-b)/2;
                if(customfunction.f(x, m)==z)
                {
                    vector<int>t = {x, m};
                    res.push_back(t);
                    e= m-1;
                }
                else if(customfunction.f(x, m)>z)
                    e = m-1;
                else
                    b = m+1;
            }
        }
        return res;
    }
};