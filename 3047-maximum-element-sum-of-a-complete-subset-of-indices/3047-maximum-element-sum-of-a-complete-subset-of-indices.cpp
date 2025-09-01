class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        
        int n = nums.size(), a;
        vector<long long> divided_by(n+1, 0);


        for(int i = 0; i<n; i++)
        {

            a = i+1;

            for(int j = 1; j*j<=a; j++)
            {
                if(a%(j*j)==0)
                {
                    divided_by[a/(j*j)] += nums[i];
                }
            }
        }

        long long maxi = 0;

        for(int i = 0; i<n; i++)
        {
            maxi = max(maxi, divided_by[i+1]);
        }

        return maxi;
    }
};