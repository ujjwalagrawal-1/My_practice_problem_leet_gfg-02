class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0;
        int r = h.size()-1;
        int lft = 0;int rgt = 0;
        int ans = 0;
        while(l<r){
            if(h[l] <= h[r]){
                if(lft < h[l])lft = h[l];
                else{
                    ans += lft - h[l];
                    l++;
                }
            }
            else{
                if(rgt < h[r]){
                    rgt = h[r];
                }
                else{
                    ans += rgt - h[r];
                    r--;
                }
            }
        }
        return ans;
    }
};